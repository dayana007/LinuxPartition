
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <inttypes.h>
#include <sched.h>
#include <semaphore.h>
#include <sys/sysinfo.h>
#include "config.h"
#include "utility.h"
#include "testcase.h"

#define THREAD0_ID 100
#define THREAD1_ID 101
#define THREAD2_ID 102
#define THREAD3_ID 103
#define THREAD4_ID 104
#define THREAD5_ID 105
#define THREAD6_ID 106
#define THREAD7_ID 107
#define THREAD8_ID 108
#define THREAD9_ID 109
#define THREAD10_ID 110
#define THREAD11_ID 111
#define THREAD12_ID 112
#define THREAD13_ID 113
#define THREAD14_ID 114
#define THREAD15_ID 115
#define THREAD16_ID 116
#define THREAD17_ID 117
#define THREAD18_ID 118
#define THREAD19_ID 119

__asm__( ".text" );
__asm__( ".align 4096" );

pthread_t pthrd_ID[TEST_THREADS_SCHED];
ThreadStatus stStatus   = {0};

void* TD0( void* argt );
void* TD1( void* argt );
void* TD2( void* argt );
void* TD3( void* argt );
void* TD4( void* argt );
void* TD5( void* argt );
void* TD6( void* argt );
void* TD7( void* argt );
void* TD8( void* argt );
void* TD9( void* argt );
void* TD10( void* argt );
void* TD11( void* argt );
void* TD12( void* argt );
void* TD13( void* argt );
void* TD14( void* argt );
void* TD15( void* argt );
void* TD16( void* argt );
void* TD17( void* argt );
void* TD18( void* argt );
void* TD19( void* argt );
void* TDEnd( void );

void* TD0( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 0 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD0_ID );
    stStatus.u8TD0Complete = 1;

    return (void*)NULL;
}

void* TD1( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 1 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD1_ID );
    stStatus.u8TD1Complete = 1;

    return (void*)NULL;
}

void* TD2( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 2 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD2_ID );
    stStatus.u8TD2Complete = 1;

    return (void*)NULL;
}

void* TD3( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 3 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD3_ID );
    stStatus.u8TD3Complete = 1;

    return (void*)NULL;
}

void* TD4( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 4 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD4_ID );
    stStatus.u8TD4Complete = 1;

    return (void*)NULL;
}

void* TD5( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 5 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD5_ID );
    stStatus.u8TD5Complete = 1;

    return (void*)NULL;
}

void* TD6( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 6 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD6_ID );
    stStatus.u8TD6Complete = 1;

    return (void*)NULL;
}

void* TD7( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 7 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD7_ID );
    stStatus.u8TD7Complete = 1;

    return (void*)NULL;
}

void* TD8( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 8 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD8_ID );
    stStatus.u8TD8Complete = 1;

    return (void*)NULL;
}

void* TD9( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 9 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD9_ID );
    stStatus.u8TD9Complete = 1;

    return (void*)NULL;
}

void* TD10( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 10 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD10_ID );
    stStatus.u8TD10Complete = 1;

    return (void*)NULL;
}

void* TD11( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 11 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD11_ID );
    stStatus.u8TD11Complete = 1;

    return (void*)NULL;
}

void* TD12( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 12 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD12_ID );
    stStatus.u8TD12Complete = 1;

    return (void*)NULL;
}

void* TD13( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 13 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD13_ID );
    stStatus.u8TD13Complete = 1;

    return (void*)NULL;
}

void* TD14( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 14 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD14_ID );
    stStatus.u8TD14Complete = 1;

    return (void*)NULL;
}

void* TD15( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 15 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD15_ID );
    stStatus.u8TD15Complete = 1;

    return (void*)NULL;
}

void* TD16( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 16 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD16_ID );
    stStatus.u8TD16Complete = 1;

    return (void*)NULL;
}

void* TD17( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 17 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD17_ID );
    stStatus.u8TD17Complete = 1;

    return (void*)NULL;
}

void* TD18( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 18 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD18_ID );
    stStatus.u8TD18Complete = 1;

    return (void*)NULL;
}

void* TD19( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 19 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );
    printf( "%d\n", THREAD19_ID );
    stStatus.u8TD19Complete = 1;

    return (void*)NULL;
}

void* TDEnd( void )
{
    return (void*)NULL;
}

FP_Thrd fpArr[TEST_THREADS] = {
			TD0,
			TD1,
			TD2,
			TD3,
			TD4,
			TD5,
			TD6,
			TD7,
			TD8,
			TD9,
			TD10,
			TD11,
			TD12,
			TD13,
			TD14,
			TD15,
			TD16,
			TD17,
			TD18,
			TD19
		};

int main( void )
{
  void* vPtr1 = ( void *)TD0;
  void* vPtr2 = ( void *)TDEnd;
  void* vPtr  = ( void *)NULL;
  int err;
  /* Check if vPtr2 is greater than vPtr1, otherwise something is seriously wrong */
  const uint32_t cu32Size = ( vPtr2 > vPtr1 )?( vPtr2 - vPtr1 ):0;
  int rc;
  int pagesize;
  char *p;
  int i;
  int j                   = TESTID_CODESECTION_INTEGRITYTEST;
  const uint8_t coreCount = get_nprocs();
  uint32_t u32ThreadCodeSectionSizes[TEST_THREADS-1] = {0};

  printf( "************Test Case ID %d************\n", j );
  printf( "This system has %d processors configured and %d processors available.\n", get_nprocs_conf(), get_nprocs() );
  printf( "Starting address of TD0=0x%08X.\n", TD0 );
  printf( "Starting address of TD1=0x%08X.\n", TD1 );
  printf( "Starting address of TD2=0x%08X.\n", TD2 );
  printf( "Starting address of TD3=0x%08X.\n", TD3 );
  printf( "Starting address of TD4=0x%08X.\n", TD4 );
  printf( "Starting address of TD5=0x%08X.\n", TD5 );
  printf( "Starting address of TD6=0x%08X.\n", TD6 );
  printf( "Starting address of TD7=0x%08X.\n", TD7 );
  printf( "Starting address of TD8=0x%08X.\n", TD8 );
  printf( "Starting address of TD9=0x%08X.\n", TD9 );
  printf( "Starting address of TD10=0x%08X.\n", TD10 );
  printf( "Starting address of TD11=0x%08X.\n", TD11 );
  printf( "Starting address of TD12=0x%08X.\n", TD12 );
  printf( "Starting address of TD13=0x%08X.\n", TD13 );
  printf( "Starting address of TD14=0x%08X.\n", TD14 );
  printf( "Starting address of TD15=0x%08X.\n", TD15 );
  printf( "Starting address of TD16=0x%08X.\n", TD16 );
  printf( "Starting address of TD17=0x%08X.\n", TD17 );
  printf( "Starting address of TD18=0x%08X.\n", TD18 );
  printf( "Starting address of TD19=0x%08X.\n", TD19 );
  printf( "Starting address of TDEnd=0x%08X.\n", TDEnd );

  u32ThreadCodeSectionSizes[0]  = TD1 - TD0;
  u32ThreadCodeSectionSizes[1]  = TD2 - TD1;
  u32ThreadCodeSectionSizes[2]  = TD3 - TD2;
  u32ThreadCodeSectionSizes[3]  = TD4 - TD3;
  u32ThreadCodeSectionSizes[4]  = TD5 - TD4;
  u32ThreadCodeSectionSizes[5]  = TD6 - TD5;
  u32ThreadCodeSectionSizes[6]  = TD7 - TD6;
  u32ThreadCodeSectionSizes[7]  = TD8 - TD7;
  u32ThreadCodeSectionSizes[8]  = TD9 - TD8;
  u32ThreadCodeSectionSizes[9]  = TD10 - TD9;
  u32ThreadCodeSectionSizes[10] = TD11 - TD10;
  u32ThreadCodeSectionSizes[11] = TD12 - TD11;
  u32ThreadCodeSectionSizes[12] = TD13 - TD12;
  u32ThreadCodeSectionSizes[13] = TD14 - TD13;
  u32ThreadCodeSectionSizes[14] = TD15 - TD14;
  u32ThreadCodeSectionSizes[15] = TD16 - TD15;
  u32ThreadCodeSectionSizes[16] = TD17 - TD16;
  u32ThreadCodeSectionSizes[17] = TD18 - TD17;
  u32ThreadCodeSectionSizes[18] = TD19 - TD18;
  for( i = 0; i < ( TEST_THREADS - 1); i++ )
  {
      printf( "Size of Thread%d = %d\n", i, u32ThreadCodeSectionSizes[i] );
  }

  /* Allocate and initialize memory */
  vPtr1 = malloc( cu32Size );
  vPtr2 = malloc( cu32Size );
  if( ( NULL != vPtr1 ) && ( NULL != vPtr2 ) )
  {
      memset( vPtr1, 0, cu32Size );
      memset( vPtr2, 0, cu32Size );
  }

  /* Get page size for this system, need to see the equivalent api in PikoOS */
  pagesize = sysconf( _SC_PAGE_SIZE );
  if( pagesize == -1 )
    return 1;

  /* p is prepared to be in the boundary of the page size. mprotect API needs the address field in the boundary of Page size*/
  p    = (char*) TD0;
  vPtr = (char*) TD0;
  printf( "p=0x%08X.\n", p );
  p = (char*) ((size_t) p & ~(pagesize - 1));
  printf( "p=0x%08X.\n", p );

  /* Copy before permission changes */
  vPtr = TD0;
  for( i = 0; i < (size_t)cu32Size; i++ )
  {
      ((char*) vPtr1)[ i ] = ((char*) vPtr)[ i ];
  }

  /* Change the permissions of a PAGE of memory starting from the address of TD0 in code segment */
  rc = mprotect( p, pagesize, PROT_READ | PROT_WRITE | PROT_EXEC );
  if( rc != 0 )
    return( 2 );

  /* Copy after permission changes */
  vPtr = TD0;
  for( i = 0; i < (size_t)cu32Size; i++ )
  {
      ((char*) vPtr2)[ i ] = ((char*) vPtr)[ i ];
  }


  /* Compare two copies, should be the same as no modifications have happened  */
  if( 0 == memcmp( vPtr1, vPtr2, cu32Size ) )
    printf( "Test success \n" );

  /* Mutate the code segment for function TD0 */
  for( i = 0; i < (size_t) TD1 - (size_t) TD0; i++ )
  {
      if( ((char*) TD1)[ i ] == 101 )
      {
        printf( "i=%d.\n", i );
        ((char*) TD0)[ i ] = ((char*) TD1)[ i ];
      }
  }

  /* Copy after mutation, verify that the copies are indeed different */
  vPtr = TD0;
  for( i = 0; i < (size_t)cu32Size; i++ )
  {
      ((char*) vPtr2)[ i ] = ((char*) vPtr)[ i ];
  }

  /* Compare two copies, should be different as modifications have already happened  */
  if( 0 != memcmp( vPtr1, vPtr2, cu32Size ) )
    printf( "Test success \n" );

  /* Synchronize the buffer contents, vPtr2 is already ready, prepare vPtr1 */
  vPtr = TD0;
  for( i = 0; i < (size_t)cu32Size; i++ )
  {
      ((char*) vPtr1)[ i ] = ((char*) vPtr)[ i ];
  }

  /* Start the threads */
  for( i = 0; i < TEST_THREADS/2; i++ )
  {
    err = pthread_create( &pthrd_ID[i], NULL, fpArr[i], &j );
    if( SUCCESS != err )
      printf( "pthread_create() on pThread %d failed\n", i );
  }

  /* Keep waiting until all threads are automatically complete */
  /* Trigger via IPC to trigger application loop start in secure partition in Pike OS */
  while( 1 )
  {
      usleep( 1 );
      if( stStatus.u8TD0Complete == 1 )
      {
           if( stStatus.u8TD1Complete == 1 )
           {
               if( stStatus.u8TD2Complete == 1 )
               {
                   if( stStatus.u8TD3Complete == 1 )
                   {
                        if( stStatus.u8TD4Complete == 1 )
                        {
                            if( stStatus.u8TD5Complete == 1 )
                            {
                                if( stStatus.u8TD6Complete == 1 )
                                {
                                    if( stStatus.u8TD7Complete == 1 )
                                    {
                                        if( stStatus.u8TD8Complete == 1 )
                                        {
                                            if( stStatus.u8TD9Complete == 1 )
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                   }
               }
           }
      }
  }
  /* Trigger via IPC to trigger application loop stop in secure partition in Pike OS */


  /* Copy after running the threads, verify that no new mutations have occured */
  vPtr = TD0;
  for( i = 0; i < (size_t)cu32Size; i++ )
  {
      ((char*) vPtr2)[ i ] = ((char*) vPtr)[ i ];
  }


  /* Compare two copies, should be the same. If not test has failed.
     The run of threads on various CPU cores should not corrupt the code section in any way
     This test case verifies memory protection of the code section under the influence of
     the run of a multithreaded application
  */
  if( 0 == memcmp( vPtr1, vPtr2, cu32Size ) )
    printf( "Test success \n" );

  return( 0 );
}
