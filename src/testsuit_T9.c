#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <sched.h>
#include <inttypes.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "config.h"
#include "utility.h"
#include "testcase.h"

/* Participating thread count in QOS calculation */
#define TEST_THREADS_QOS 8
/* Total number of fifo */
#define FIFO_COUNT ( TEST_THREADS_QOS/2 )
/* Define for communication from TD0 to TD1 and back */
#define THREAD_0_1 0
/* Define for communication from TD2 to TD3 and back */
#define THREAD_2_3 1
/* Define for communication from TD4 to TD5 and back */
#define THREAD_4_5 2
/* Define for communication from TD6 to TD7 and back */
#define THREAD_6_7 3
/* Pattern from Thread 0 to Thread 1 */
#define PATTERN_A 'A'
/* Pattern from Thread 1 to Thread 0 */
#define PATTERN_B 'B'
/* Pattern from Thread 2 to Thread 3 */
#define PATTERN_C 'C'
/* Pattern from Thread 3 to Thread 2 */
#define PATTERN_D 'D'
/* Pattern from Thread 4 to Thread 5 */
#define PATTERN_E 'E'
/* Pattern from Thread 5 to Thread 4 */
#define PATTERN_F 'F'
/* Pattern from Thread 6 to Thread 7 */
#define PATTERN_G 'G'
/* Pattern from Thread 7 to Thread 6 */
#define PATTERN_H 'H'

extern int sched_getcpu(void);

pthread_t pthrd_ID[TEST_THREADS_QOS];
ThreadStatus stStatus     = {0};
Fifo  stFifo[FIFO_COUNT]  = {0};

void* TD0( void* argt )
{
    /* Local Variables */
    int fd;
    char cArrayTD0[PAGE_SIZE] = {'\0'};

    /* Know in which CPU this thread is scheduled */
    int inCpu = sched_getcpu();
    printf( "PThread 0 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    /* Prepare the buffer */
    memset( cArrayTD0, PATTERN_A, ( PAGE_SIZE - 1 ) );

    /* Open FIFO for write only */
    fd = open( stFifo[0].fifoName, O_WRONLY );
    if( 0 < fd )
    {
        /* Signal Thread 1 that Thread 0 is read with data */
        sem_post( &stFifo[0].mutex );

        /* Measure the time here */
        clock_gettime( CLOCK_REALTIME, &stFifo[0].startTime_DIR0 );

        /* Write to Fifo */
        if( 0 < write( fd, cArrayTD0, PAGE_SIZE ) )
        {
            printf( "TD0 : Write success\n");
        }
        else
        {
            perror("TD0( write ): ");
        }
        /* Close the file descriptor */
        close(fd);

        while( stFifo[0].u8TransferComplete_DIR0 == 0 )
        {
            usleep(1);
        }
        
        /* Open FIFO for read only */
        fd = open( stFifo[0].fifoName, O_RDONLY );
        if( 0 < fd )
        {
            /* Wait for signal from Thread 0 */
            sem_wait( &stFifo[0].mutex );

            /* Read from Fifo */
            if( 0 < read( fd, cArrayTD0, PAGE_SIZE ) )
            {
                /* Direction 0 transfer from Thread 0 to Thread 1 complete */
                stFifo[0].u8TransferComplete_DIR1 = 1;
            }
            else
            {
                perror("TD1( read ): ");
            }

            /* Close the file descriptor */
            close(fd);
        }
        else
        {
            perror("TD0( read back open ): ");
        }
    }
    else
    {
        perror("TD0( open ): ");
    }

    stStatus.u8TD0Complete = 1;

    return (void*)NULL;
}

void* TD1( void* argt )
{
    /* Local Variables */
    int iIndex = 0;
    int fd;
    char cArrayTD1[PAGE_SIZE] = {'\0'};

    /* Know in which CPU this thread is scheduled */
    int inCpu = sched_getcpu();
    printf( "PThread 1 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );


    /* Open FIFO for write only */
    fd = open( stFifo[0].fifoName, O_RDONLY );
    if( 0 < fd )
    {
        /* Wait for signal from Thread 0 */
        sem_wait( &stFifo[0].mutex );

        /* Read from Fifo */
        if( 0 < read( fd, cArrayTD1, PAGE_SIZE ) )
        {
            /* Direction 0 transfer from Thread 0 to Thread 1 complete */
            stFifo[0].u8TransferComplete_DIR0 = 1;
        }
        else
        {
            perror("TD1( read ): ");
        }

        /* Measure the time here */
        clock_gettime( CLOCK_REALTIME, &stFifo[0].endTime_DIR0 );

        /* Check for the integrity of the received data in Thread 1*/
        for( ;iIndex < ( PAGE_SIZE - 1 ); iIndex++ )
        {
            if( PATTERN_A != cArrayTD1[iIndex] )
            {
                printf( "TD1 : Data Transfer from T0 to T1 failed at index %d", iIndex );
                /* If wrong data is seen, set this field to indicate transfer failure*/
                stFifo[0].u8TransferComplete_DIR0 = 0;
                break;
            }
        }

        /* Close the file descriptor */
        close(fd);

        /* Open FIFO for write only */
        fd = open( stFifo[0].fifoName, O_WRONLY );
        if( 0 < fd )
        {
            /* Signal Thread 0 that Thread 1 is ready with data */
            sem_post( &stFifo[0].mutex );

            /* Measure the time here */
            clock_gettime( CLOCK_REALTIME, &stFifo[0].startTime_DIR0 );

            /* Write to Fifo */
            if( 0 < write( fd, cArrayTD0, PAGE_SIZE ) )
            {
                printf( "TD1 : Write back success\n");
            }
            else
            {
                perror("TD1( write back): ");
            }

            /* Close the file descriptor */
            close(fd);
        }
    }
    else
    {
        perror("TD1( open ): ");
    }

    stStatus.u8TD1Complete = 1;

    return (void*)NULL;
}

void* TD2( void* argt )
{
  /* Local Variables */
  int fd;
  char cArrayTD2[PAGE_SIZE] = {'\0'};

  /* Know in which CPU this thread is scheduled */
  int inCpu = sched_getcpu();
  printf( "PThread 2 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

  /* Prepare the buffer */
  memset( cArrayTD2, PATTERN_C, ( PAGE_SIZE - 1 ) );

  /* Open FIFO for write only */
  fd = open( stFifo[1].fifoName, O_WRONLY );
  if( 0 < fd )
  {
      /* Signal Thread 1 that Thread 0 is read with data */
      sem_post( &stFifo[1].mutex );

      /* Measure the time here */
      clock_gettime( CLOCK_REALTIME, &stFifo[1].startTime_DIR0 );

      /* Write to Fifo */
      if( 0 < write( fd, cArrayTD2, PAGE_SIZE ) )
      {
          printf( "TD2 : Write success\n");
      }
      else
      {
          perror("TD2( write ): ");
      }
      /* Close the file descriptor */
      close(fd);
  }
  else
  {
      perror("TD2( open ): ");
  }

  stStatus.u8TD2Complete = 1;

  return (void*)NULL;
}

void* TD3( void* argt )
{
  /* Local Variables */
  int iIndex = 0;
  int fd;
  char cArrayTD3[PAGE_SIZE] = {'\0'};

  /* Know in which CPU this thread is scheduled */
  int inCpu = sched_getcpu();
  printf( "PThread 3 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );


  /* Open FIFO for write only */
  fd = open( stFifo[1].fifoName, O_RDONLY );
  if( 0 < fd )
  {
      /* Wait for signal from Thread 0 */
      sem_wait( &stFifo[1].mutex );

      /* Read from Fifo */
      if( 0 < read( fd, cArrayTD3, PAGE_SIZE ) )
      {
          /* Direction 0 transfer from Thread 0 to Thread 1 complete */
          stFifo[1].u8TransferComplete_DIR0 = 1;
      }
      else
      {
          perror("TD3( read ): ");
      }

      /* Measure the time here */
      clock_gettime( CLOCK_REALTIME, &stFifo[1].endTime_DIR0 );

      /* Check for the integrity of the received data in Thread 1*/
      for( ;iIndex < ( PAGE_SIZE - 1 ); iIndex++ )
      {
          if( PATTERN_C != cArrayTD3[iIndex] )
          {
              printf( "TD3 : Data Transfer from T2 to T3 failed at index %d", iIndex );
              /* If wrong data is seen, set this field to indicate transfer failure*/
              stFifo[1].u8TransferComplete_DIR0 = 0;
              break;
          }
      }

      /* Close the file descriptor */
      close(fd);
  }
  else
  {
      perror("TD3( open ): ");
  }

  stStatus.u8TD3Complete = 1;

  return (void*)NULL;
}

void* TD4( void* argt )
{
  /* Local Variables */
  int fd;
  char cArrayTD4[PAGE_SIZE] = {'\0'};

  /* Know in which CPU this thread is scheduled */
  int inCpu = sched_getcpu();
  printf( "PThread 4 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

  /* Prepare the buffer */
  memset( cArrayTD4, PATTERN_E, ( PAGE_SIZE - 1 ) );

  /* Open FIFO for write only */
  fd = open( stFifo[2].fifoName, O_WRONLY );
  if( 0 < fd )
  {
      /* Signal Thread 1 that Thread 0 is read with data */
      sem_post( &stFifo[2].mutex );

      /* Measure the time here */
      clock_gettime( CLOCK_REALTIME, &stFifo[2].startTime_DIR0 );

      /* Write to Fifo */
      if( 0 < write( fd, cArrayTD4, PAGE_SIZE ) )
      {
          printf( "TD4 : Write success\n");
      }
      else
      {
          perror("TD4( write ): ");
      }
      /* Close the file descriptor */
      close(fd);
  }
  else
  {
      perror("TD4( open ): ");
  }

  stStatus.u8TD4Complete = 1;

  return (void*)NULL;
}

void* TD5( void* argt )
{
  /* Local Variables */
  int iIndex = 0;
  int fd;
  char cArrayTD5[PAGE_SIZE] = {'\0'};

  /* Know in which CPU this thread is scheduled */
  int inCpu = sched_getcpu();
  printf( "PThread 5 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );


  /* Open FIFO for write only */
  fd = open( stFifo[2].fifoName, O_RDONLY );
  if( 0 < fd )
  {
      /* Wait for signal from Thread 0 */
      sem_wait( &stFifo[2].mutex );

      /* Read from Fifo */
      if( 0 < read( fd, cArrayTD5, PAGE_SIZE ) )
      {
          /* Direction 0 transfer from Thread 0 to Thread 1 complete */
          stFifo[2].u8TransferComplete_DIR0 = 1;
      }
      else
      {
          perror("TD5( read ): ");
      }

      /* Measure the time here */
      clock_gettime( CLOCK_REALTIME, &stFifo[2].endTime_DIR0 );

      /* Check for the integrity of the received data in Thread 1*/
      for( ;iIndex < ( PAGE_SIZE - 1 ); iIndex++ )
      {
          if( PATTERN_E != cArrayTD5[iIndex] )
          {
              printf( "TD5 : Data Transfer from T2 to T3 failed at index %d", iIndex );
              /* If wrong data is seen, set this field to indicate transfer failure*/
              stFifo[2].u8TransferComplete_DIR0 = 0;
              break;
          }
      }

      /* Close the file descriptor */
      close(fd);
  }
  else
  {
      perror("TD5( open ): ");
  }

  stStatus.u8TD5Complete = 1;

  return (void*)NULL;
}

void* TD6( void* argt )
{
  /* Local Variables */
  int fd;
  char cArrayTD6[PAGE_SIZE] = {'\0'};

  /* Know in which CPU this thread is scheduled */
  int inCpu = sched_getcpu();
  printf( "PThread 6 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

  /* Prepare the buffer */
  memset( cArrayTD6, PATTERN_G, ( PAGE_SIZE - 1 ) );

  /* Open FIFO for write only */
  fd = open( stFifo[3].fifoName, O_WRONLY );
  if( 0 < fd )
  {
      /* Signal Thread 1 that Thread 0 is read with data */
      sem_post( &stFifo[3].mutex );

      /* Measure the time here */
      clock_gettime( CLOCK_REALTIME, &stFifo[3].startTime_DIR0 );

      /* Write to Fifo */
      if( 0 < write( fd, cArrayTD6, PAGE_SIZE ) )
      {
          printf( "TD6 : Write success\n");
      }
      else
      {
          perror("TD6( write ): ");
      }
      /* Close the file descriptor */
      close(fd);
  }
  else
  {
      perror("TD6( open ): ");
  }

  stStatus.u8TD6Complete = 1;

  return (void*)NULL;
}

void* TD7( void* argt )
{
  /* Local Variables */
  int iIndex = 0;
  int fd;
  char cArrayTD7[PAGE_SIZE] = {'\0'};

  /* Know in which CPU this thread is scheduled */
  int inCpu = sched_getcpu();
  printf( "PThread 7 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );


  /* Open FIFO for write only */
  fd = open( stFifo[3].fifoName, O_RDONLY );
  if( 0 < fd )
  {
      /* Wait for signal from Thread 0 */
      sem_wait( &stFifo[3].mutex );

      /* Read from Fifo */
      if( 0 < read( fd, cArrayTD7, PAGE_SIZE ) )
      {
          /* Direction 0 transfer from Thread 0 to Thread 1 complete */
          stFifo[3].u8TransferComplete_DIR0 = 1;
      }
      else
      {
          perror("TD7( read ): ");
      }

      /* Measure the time here */
      clock_gettime( CLOCK_REALTIME, &stFifo[3].endTime_DIR0 );

      /* Check for the integrity of the received data in Thread 1*/
      for( ;iIndex < ( PAGE_SIZE - 1 ); iIndex++ )
      {
          if( PATTERN_G != cArrayTD7[iIndex] )
          {
              printf( "TD7 : Data Transfer from T6 to T7 failed at index %d", iIndex );
              /* If wrong data is seen, set this field to indicate transfer failure*/
              stFifo[3].u8TransferComplete_DIR0 = 0;
              break;
          }
      }

      /* Close the file descriptor */
      close(fd);
  }
  else
  {
      perror("TD7( open ): ");
  }

  stStatus.u8TD7Complete = 1;

  return (void*)NULL;
}


/* TD0 <> TD1, TD2 <> TD3, TD4 <> TD5, TD6 <> TD7 */
FP_Thrd fpArr[TEST_THREADS_QOS] =
{
		TD0,
    TD1,
    TD2,
    TD3,
    TD4,
    TD5,
    TD6,
    TD7
};


int main( int argc, char** argv )
{
	 int j                   = TESTID_QOSTEST;
	 int i;
	 int err;
	 int iRes;
	 void* result = (void*)&iRes;
   FILE *fp;

   HRTime tDiff0 = {0};
   HRTime tDiff1 = {0};
   HRTime tDiff2 = {0};
   HRTime tDiff3 = {0};
   const uint8_t coreCount = get_nprocs();


	 printf( "************Test Case ID %d************\n", j );
   printf( "This system has %d processors configured and %d processors available.\n", get_nprocs_conf(), get_nprocs() );

   stFifo[0].fifoName        = "/tmp/FIFO_TD0_TD1";
   stFifo[0].fifoPermissions = S_IRWXU|S_IRWXG|S_IRWXO;
   sem_init( &stFifo[0].mutex, 0, 1 );

   stFifo[1].fifoName        = "/tmp/FIFO_TD2_TD3";
   stFifo[1].fifoPermissions = S_IRWXU|S_IRWXG|S_IRWXO;
   sem_init( &stFifo[1].mutex, 0, 1 );

   stFifo[2].fifoName        = "/tmp/FIFO_TD4_TD5";
   stFifo[2].fifoPermissions = S_IRWXU|S_IRWXG|S_IRWXO;
   sem_init( &stFifo[2].mutex, 0, 1 );

   stFifo[3].fifoName        = "/tmp/FIFO_TD6_TD7";
   stFifo[3].fifoPermissions = S_IRWXU|S_IRWXG|S_IRWXO;
   sem_init( &stFifo[3].mutex, 0, 1 );

   /* Create all FIFO objects before threads are started */
   mkfifo( stFifo[0].fifoName, stFifo[0].fifoPermissions );
   mkfifo( stFifo[1].fifoName, stFifo[1].fifoPermissions );
   mkfifo( stFifo[2].fifoName, stFifo[2].fifoPermissions );
   mkfifo( stFifo[3].fifoName, stFifo[3].fifoPermissions );

   /* Test suite run */
	 for( i = 0; i < TEST_THREADS_QOS; i++ )
	 {
       /* Creating and Starting all threads */
		   err = pthread_create( &pthrd_ID[i], NULL, fpArr[i], &j );
		   if( SUCCESS != err )
			    printf( "pthread_create() on pThread %d failed\n", i );
	 }

   sleep( 5 );

   /* tDiff0 = diff( stFifo[0].startTime_DIR0, stFifo[0].endTime_DIR0 ); */
   /* u64TimeInSecs = tDiff0.tv_sec*(1E9) + tDiff0.tv_nsec; */

   tDiff0 = diff( stFifo[0].startTime_DIR0, stFifo[0].endTime_DIR0  );
   tDiff1 = diff( stFifo[1].startTime_DIR0, stFifo[1].endTime_DIR0  );
   tDiff2 = diff( stFifo[2].startTime_DIR0, stFifo[2].endTime_DIR0  );
   tDiff3 = diff( stFifo[3].startTime_DIR0, stFifo[3].endTime_DIR0  );

   printf( "%u\n", tDiff0.tv_sec );
   printf( "%ld\n", tDiff0.tv_nsec );
   printf( "%u\n", tDiff1.tv_sec );
   printf( "%ld\n", tDiff1.tv_nsec );
   printf( "%u\n", tDiff2.tv_sec );
   printf( "%ld\n", tDiff2.tv_nsec );
   printf( "%u\n", tDiff3.tv_sec );
   printf( "%ld\n", tDiff3.tv_nsec );

   /* Remove all the named FIFO from filesystem */
   remove( stFifo[0].fifoName );
   remove( stFifo[1].fifoName );
   remove( stFifo[2].fifoName );
   remove( stFifo[3].fifoName );


}
