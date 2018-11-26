#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <inttypes.h>
#include <semaphore.h>
#include "config.h"
#include "utility.h"
#include "testcase.h"

extern int sched_getcpu(void);

pthread_t pthrd_ID[TEST_THREADS];
sem_t mutex_T3;

char cArrTD0[SIZE_10MB];
uint64_t u64ResTD0[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD0     = 0;
char cStartTD0 							 = 'A';
uint8_t u8ErrorStatusTD0     = FAILURE;

char cArrTD1[SIZE_10MB];
uint64_t u64ResTD1[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD1     = 0;
char cStartTD1 							 = 'A';
uint8_t u8ErrorStatusTD1     = FAILURE;

char cArrTD2[SIZE_10MB];
uint64_t u64ResTD2[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD2     = 0;
char cStartTD2 							 = 'A';
uint8_t u8ErrorStatusTD2     = FAILURE;

char cArrTD3[SIZE_10MB];
uint64_t u64ResTD3[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD3     = 0;
char cStartTD3 							 = 'A';
uint8_t u8ErrorStatusTD3     = FAILURE;

char cArrTD4[SIZE_10MB];
uint64_t u64ResTD4[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD4     = 0;
char cStartTD4 							 = 'A';
uint8_t u8ErrorStatusTD4     = FAILURE;

char cArrTD5[SIZE_10MB];
uint64_t u64ResTD5[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD5     = 0;
char cStartTD5 							 = 'A';
uint8_t u8ErrorStatusTD5     = FAILURE;

char cArrTD6[SIZE_10MB];
uint64_t u64ResTD6[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD6     = 0;
char cStartTD6 							 = 'A';
uint8_t u8ErrorStatusTD6     = FAILURE;

char cArrTD7[SIZE_10MB];
uint64_t u64ResTD7[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD7     = 0;
char cStartTD7 							 = 'A';
uint8_t u8ErrorStatusTD7     = FAILURE;

char cArrTD8[SIZE_10MB];
uint64_t u64ResTD8[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD8     = 0;
char cStartTD8 							 = 'A';
uint8_t u8ErrorStatusTD8     = FAILURE;

char cArrTD9[SIZE_10MB];
uint64_t u64ResTD9[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD9     = 0;
char cStartTD9 							 = 'A';
uint8_t u8ErrorStatusTD9     = FAILURE;

char cArrTD10[SIZE_10MB];
uint64_t u64ResTD10[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD10     = 0;
char cStartTD10 							= 'A';
uint8_t u8ErrorStatusTD10     = FAILURE;

char cArrTD11[SIZE_10MB];
uint64_t u64ResTD11[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD11     = 0;
char cStartTD11 							= 'A';
uint8_t u8ErrorStatusTD11     = FAILURE;

char cArrTD12[SIZE_10MB];
uint64_t u64ResTD12[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD12     = 0;
char cStartTD12 							= 'A';
uint8_t u8ErrorStatusTD12     = FAILURE;

char cArrTD13[SIZE_10MB];
uint64_t u64ResTD13[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD13     = 0;
char cStartTD13 							= 'A';
uint8_t u8ErrorStatusTD13     = FAILURE;

char cArrTD14[SIZE_10MB];
uint64_t u64ResTD14[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD14     = 0;
char cStartTD14 							= 'A';
uint8_t u8ErrorStatusTD14     = FAILURE;

char cArrTD15[SIZE_10MB];
uint64_t u64ResTD15[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD15     = 0;
char cStartTD15 							= 'A';
uint8_t u8ErrorStatusTD15     = FAILURE;

char cArrTD16[SIZE_10MB];
uint64_t u64ResTD16[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD16     = 0;
char cStartTD16 							= 'A';
uint8_t u8ErrorStatusTD16     = FAILURE;

char cArrTD17[SIZE_10MB];
uint64_t u64ResTD17[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD17     = 0;
char cStartTD17 							= 'A';
uint8_t u8ErrorStatusTD17     = FAILURE;

char cArrTD18[SIZE_10MB];
uint64_t u64ResTD18[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD18     = 0;
char cStartTD18 							= 'A';
uint8_t u8ErrorStatusTD18     = FAILURE;

char cArrTD19[SIZE_10MB];
uint64_t u64ResTD19[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD19     = 0;
char cStartTD19 							= 'A';
uint8_t u8ErrorStatusTD19     = FAILURE;

char cArrTemp[SIZE_10MB];


void* TD0( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

  inCpu = sched_getcpu();
	iTestSuitID = *( (int*)argt );

	printf( "PThread 0 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
				 /* Prepare test */
         u64TimeIndexTD0 = 0;
         memset( u64ResTD0, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD0[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0.0;

         while(1)
         {
					   //sem_wait(&mutex_T3);
						 clock_gettime( CLOCK_REALTIME, &timeStart );
             for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
             {
	              cTemp = cArrTD0[u64Index];
             }
             clock_gettime( CLOCK_REALTIME, &timeEnd );
						 //sem_post(&mutex_T3);

             usleep( 1 );
					   cTemp = cTemp;

             if( u64TimeIndexTD0  < SIZE_OF_REPEATS )
             {
            			/* Calculate time difference */
                  timeDiff    = diff( timeStart, timeEnd );
                  u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                  u64ResTD0[u64TimeIndexTD0] = u64TimeInSecs;
             }
						 else
						 {
								printf( "Breaking off TD0\n" );
								break;
						 }
             u64TimeIndexTD0++;
				}
				break;
			default:
				 break;
	} /* switch */

	return (void*)NULL;
}

void* TD1( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 1 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD1 = 0;
      	 memset( u64ResTD1, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD1[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD1[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD1  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD1[u64TimeIndexTD1] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD1\n" );
							 break;
						}
            u64TimeIndexTD1++;
					}
          break;

			default:
				 break;
	}
	return (void*)NULL;
}

void* TD2( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 2 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD2 = 0;
      	 memset( u64ResTD2, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD2[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD2[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD2  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD2[u64TimeIndexTD2] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD2\n" );
							 break;
						}
            u64TimeIndexTD2++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD3( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 3 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD3 = 0;
      	 memset( u64ResTD3, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD3[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD3[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD3  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD3[u64TimeIndexTD3] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD3\n" );
							 break;
						}
            u64TimeIndexTD3++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD4( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 4 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD4 = 0;
      	 memset( u64ResTD4, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD4[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD4[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD4  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD4[u64TimeIndexTD4] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD4\n" );
							 break;
						}
            u64TimeIndexTD4++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD5( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

  inCpu = sched_getcpu();
	iTestSuitID = *( (int*)argt );

	printf( "PThread 5 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
				 /* Prepare test */
         u64TimeIndexTD5 = 0;
         memset( u64ResTD5, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD5[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0.0;

         while(1)
         {
					   //sem_wait(&mutex_T3);
						 clock_gettime( CLOCK_REALTIME, &timeStart );
             for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
             {
	              cTemp = cArrTD5[u64Index];
             }
             clock_gettime( CLOCK_REALTIME, &timeEnd );
						 //sem_post(&mutex_T3);

             usleep( 1 );
					   cTemp = cTemp;

             if( u64TimeIndexTD5  < SIZE_OF_REPEATS )
             {
            			/* Calculate time difference */
                  timeDiff    = diff( timeStart, timeEnd );
                  u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                  u64ResTD5[u64TimeIndexTD5] = u64TimeInSecs;
             }
						 else
						 {
								printf( "Breaking off TD5\n" );
								break;
						 }
             u64TimeIndexTD5++;
				}
				break;
			default:
				 break;
	} /* switch */

	return (void*)NULL;
}

void* TD6( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 6 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD6 = 0;
      	 memset( u64ResTD6, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD6[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD6[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD6  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD6[u64TimeIndexTD6] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD6\n" );
							 break;
						}
            u64TimeIndexTD6++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD7( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 7 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD7 = 0;
      	 memset( u64ResTD7, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD7[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD7[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD7  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD7[u64TimeIndexTD7] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD7\n" );
							 break;
						}
            u64TimeIndexTD7++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD8( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 8 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD8 = 0;
      	 memset( u64ResTD8, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD8[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD8[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD8  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD8[u64TimeIndexTD8] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD8\n" );
							 break;
						}
            u64TimeIndexTD8++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD9( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 9 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD9 = 0;
      	 memset( u64ResTD9, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD9[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD9[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD9  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD9[u64TimeIndexTD9] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD9\n" );
							 break;
						}
            u64TimeIndexTD9++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD10( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

  inCpu = sched_getcpu();
	iTestSuitID = *( (int*)argt );

	printf( "PThread 10 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
				 /* Prepare test */
         u64TimeIndexTD10 = 0;
         memset( u64ResTD10, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD10[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0.0;

         while(1)
         {
					   //sem_wait(&mutex_T3);
						 clock_gettime( CLOCK_REALTIME, &timeStart );
             for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
             {
	              cTemp = cArrTD10[u64Index];
             }
             clock_gettime( CLOCK_REALTIME, &timeEnd );
						 //sem_post(&mutex_T3);

             usleep( 1 );
					   cTemp = cTemp;

             if( u64TimeIndexTD10  < SIZE_OF_REPEATS )
             {
            			/* Calculate time difference */
                  timeDiff    = diff( timeStart, timeEnd );
                  u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                  u64ResTD10[u64TimeIndexTD10] = u64TimeInSecs;
             }
						 else
						 {
								printf( "Breaking off TD10\n" );
								break;
						 }
             u64TimeIndexTD10++;
				}
				break;
			default:
				 break;
	} /* switch */

	return (void*)NULL;
}

void* TD11( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 11 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD11 = 0;
      	 memset( u64ResTD11, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD11[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD11[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD11  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD11[u64TimeIndexTD11] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD11\n" );
							 break;
						}
            u64TimeIndexTD11++;
					}
          break;

			default:
				 break;
	}
	return (void*)NULL;
}

void* TD12( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 12 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD12 = 0;
      	 memset( u64ResTD12, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD12[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD12[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD12  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD12[u64TimeIndexTD12] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD12\n" );
							 break;
						}
            u64TimeIndexTD12++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD13( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 13 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD13 = 0;
      	 memset( u64ResTD13, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD13[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD13[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD13  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD13[u64TimeIndexTD13] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD13\n" );
							 break;
						}
            u64TimeIndexTD13++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD14( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 14 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD14 = 0;
      	 memset( u64ResTD14, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
							 cArrTD14[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD14[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD14  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD14[u64TimeIndexTD14] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD14\n" );
							 break;
						}
            u64TimeIndexTD14++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD15( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

  inCpu = sched_getcpu();
	iTestSuitID = *( (int*)argt );

	printf( "PThread 15 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
				 /* Prepare test */
         u64TimeIndexTD15 = 0;
         memset( u64ResTD15, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
				 			cArrTD15[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0.0;

         while(1)
         {
					   //sem_wait(&mutex_T3);
						 clock_gettime( CLOCK_REALTIME, &timeStart );
             for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
             {
	              cTemp = cArrTD15[u64Index];
             }
             clock_gettime( CLOCK_REALTIME, &timeEnd );
						 //sem_post(&mutex_T3);

             usleep( 1 );
					   cTemp = cTemp;

             if( u64TimeIndexTD15  < SIZE_OF_REPEATS )
             {
            			/* Calculate time difference */
                  timeDiff    = diff( timeStart, timeEnd );
                  u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                  u64ResTD15[u64TimeIndexTD15] = u64TimeInSecs;
             }
						 else
						 {
								printf( "Breaking off TD15\n" );
								break;
						 }
             u64TimeIndexTD15++;
				}
				break;
			default:
				 break;
	} /* switch */

	return (void*)NULL;
}

void* TD16( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 16 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD16 = 0;
      	 memset( u64ResTD16, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
				 			cArrTD16[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD16[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD16  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD16[u64TimeIndexTD16] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD16\n" );
							 break;
						}
            u64TimeIndexTD16++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD17( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 17 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD17 = 0;
      	 memset( u64ResTD17, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
				 			cArrTD17[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD17[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD17  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD17[u64TimeIndexTD17] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD17\n" );
							 break;
						}
            u64TimeIndexTD17++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD18( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 18 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD18 = 0;
      	 memset( u64ResTD18, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
				 			cArrTD18[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD18[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD18  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD18[u64TimeIndexTD18] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD18\n" );
							 break;
						}
            u64TimeIndexTD18++;
					}
          break;

			default:
				 break;
	}

	return (void*)NULL;
}

void* TD19( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	char cTemp;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 19 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY:
         /* Prepare test */
				 u64TimeIndexTD19 = 0;
      	 memset( u64ResTD19, 0, SIZE_1MB );

				 /* Prepare source buffer */
				 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
				 {
				 			cArrTD19[u64Index] = ( u64Index*iTestSuitID ) % 0xff;
				 }

         u64TimeInSecs = 0;

         while(1)
         {
					  //sem_wait(&mutex_T3);
						clock_gettime( CLOCK_REALTIME, &timeStart );
            for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
            {
							  cTemp = cArrTD19[u64Index];
            }
            clock_gettime( CLOCK_REALTIME, &timeEnd );
						//sem_post(&mutex_T3);

            usleep( 1 );
					  cTemp = cTemp;

            if( u64TimeIndexTD19  < SIZE_OF_REPEATS )
            {
                /* Calculate time difference */
                timeDiff    = diff( timeStart, timeEnd );
                u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
                u64ResTD19[u64TimeIndexTD19] = u64TimeInSecs;
            }
						else
						{
							 printf( "Breaking off TD19\n" );
							 break;
						}
            u64TimeIndexTD19++;
					}
          break;

			default:
				 break;
	}

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

int main( int argc, char** argv )
{
	int i;
	int j;
	int err;
	FILE *fp;
	j = TESTID_CACHE_NONJUMP_ARRAYTOVAR_CPY;

	printf( "************Test Case ID %d************\n", j );
	sem_init(&mutex_T3, 0, 1);

	/* Test suite run */
	for( i = 0; i < TEST_THREADS; i++ )
	{
		/* Creating and Starting all threads */
		err = pthread_create( &pthrd_ID[i], NULL, fpArr[i], &j );
		if( SUCCESS != err )
			printf( "pthread_create() on pThread %d failed\n", i );
	}

	/* Trigger via IPC to trigger application loop start in secure partition in Pike OS */
	while( 1 )
	{
			sleep( 1 );
			printf( "TD0(%lld)TD1(%lld)TD2(%lld)TD3(%lld)TD4(%lld)TD5(%lld)TD6(%lld)TD7(%lld)TD8(%lld)TD9(%lld)TD10(%lld)TD11(%lld)TD12(%lld)TD13(%lld)TD14(%lld)TD15(%lld)TD16(%lld)TD17(%lld)TD18(%lld)TD19(%lld)\n",
							 u64TimeIndexTD0,
							 u64TimeIndexTD1,
							 u64TimeIndexTD2,
							 u64TimeIndexTD3,
							 u64TimeIndexTD4,
							 u64TimeIndexTD5,
							 u64TimeIndexTD6,
							 u64TimeIndexTD7,
							 u64TimeIndexTD8,
							 u64TimeIndexTD9,
							 u64TimeIndexTD10,
							 u64TimeIndexTD11,
							 u64TimeIndexTD12,
							 u64TimeIndexTD13,
							 u64TimeIndexTD14,
							 u64TimeIndexTD15,
							 u64TimeIndexTD16,
							 u64TimeIndexTD17,
							 u64TimeIndexTD18,
							 u64TimeIndexTD19 );

			if( u64TimeIndexTD0 == SIZE_OF_REPEATS )
			{
					if( u64TimeIndexTD1 == SIZE_OF_REPEATS )
					{
							if( u64TimeIndexTD2 == SIZE_OF_REPEATS )
						 	{
						 			if( u64TimeIndexTD3 == SIZE_OF_REPEATS )
						 			{
						 					if( u64TimeIndexTD4 == SIZE_OF_REPEATS )
						 					{
						 							if( u64TimeIndexTD5 == SIZE_OF_REPEATS )
						 							{
						 									if( u64TimeIndexTD6 == SIZE_OF_REPEATS )
						 									{
						 											if( u64TimeIndexTD7 == SIZE_OF_REPEATS )
						 											{
						 													if( u64TimeIndexTD8 == SIZE_OF_REPEATS )
						 													{
						 															if( u64TimeIndexTD9 == SIZE_OF_REPEATS )
						 															{
						 																	if( u64TimeIndexTD10 == SIZE_OF_REPEATS )
						 																	{
						 																			if( u64TimeIndexTD11 == SIZE_OF_REPEATS )
						 																			{
						 																					if( u64TimeIndexTD12 == SIZE_OF_REPEATS )
						 																					{
						 																							if( u64TimeIndexTD13 == SIZE_OF_REPEATS )
						 																							{
						 																									if( u64TimeIndexTD14 == SIZE_OF_REPEATS )
						 																									{
						 																											if( u64TimeIndexTD15 == SIZE_OF_REPEATS )
						 																											{
						 																													if( u64TimeIndexTD16 == SIZE_OF_REPEATS )
						 																													{
						 																															if( u64TimeIndexTD17 == SIZE_OF_REPEATS )
						 																															{
						 																																	if( u64TimeIndexTD18 == SIZE_OF_REPEATS )
						 																																	{
						 																																			if( u64TimeIndexTD19 == SIZE_OF_REPEATS )
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

	printf( "Thread 0 execution time min = %lld max = %lld from %lld repeats\n",
        min( u64ResTD0, u64TimeIndexTD0 ), max( u64ResTD0, u64TimeIndexTD0 ), u64TimeIndexTD0 );
	printf( "Thread 1 execution time min = %lld max = %lld from %lld repeats\n",
        min( u64ResTD1, u64TimeIndexTD1 ), max( u64ResTD1, u64TimeIndexTD1 ), u64TimeIndexTD1 );
	printf( "Thread 2 execution time min = %lld max = %lld from %lld repeats\n",
        min( u64ResTD2, u64TimeIndexTD2 ), max( u64ResTD2, u64TimeIndexTD2 ), u64TimeIndexTD2 );
	printf( "Thread 3 execution time min = %lld max = %lld from %lld repeats\n",
        min( u64ResTD3, u64TimeIndexTD3 ), max( u64ResTD3, u64TimeIndexTD3 ), u64TimeIndexTD3 );
	printf( "Thread 4 execution time min = %lld max = %lld from %lld repeats\n",
        min( u64ResTD4, u64TimeIndexTD4 ), max( u64ResTD4, u64TimeIndexTD4 ), u64TimeIndexTD4 );
	printf( "Thread 5 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD5, u64TimeIndexTD5 ), max( u64ResTD5, u64TimeIndexTD5 ), u64TimeIndexTD5 );
	printf( "Thread 6 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD6, u64TimeIndexTD6 ), max( u64ResTD6, u64TimeIndexTD6 ), u64TimeIndexTD6 );
	printf( "Thread 7 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD7, u64TimeIndexTD7 ), max( u64ResTD7, u64TimeIndexTD7 ), u64TimeIndexTD7 );
	printf( "Thread 8 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD8, u64TimeIndexTD8 ), max( u64ResTD8, u64TimeIndexTD8 ), u64TimeIndexTD8 );
	printf( "Thread 9 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD9, u64TimeIndexTD9 ), max( u64ResTD9, u64TimeIndexTD9 ), u64TimeIndexTD9 );
	printf( "Thread 10 execution time min = %lld max = %lld from %lld repeats\n",
			  min( u64ResTD10, u64TimeIndexTD10 ), max( u64ResTD10, u64TimeIndexTD10 ), u64TimeIndexTD10 );
	printf( "Thread 11 execution time min = %lld max = %lld from %lld repeats\n",
			  min( u64ResTD11, u64TimeIndexTD11 ), max( u64ResTD11, u64TimeIndexTD11 ), u64TimeIndexTD11 );
	printf( "Thread 12 execution time min = %lld max = %lld from %lld repeats\n",
			  min( u64ResTD12, u64TimeIndexTD12 ), max( u64ResTD12, u64TimeIndexTD12 ), u64TimeIndexTD12 );
	printf( "Thread 13 execution time min = %lld max = %lld from %lld repeats\n",
			  min( u64ResTD13, u64TimeIndexTD13 ), max( u64ResTD13, u64TimeIndexTD13 ), u64TimeIndexTD13 );
	printf( "Thread 14 execution time min = %lld max = %lld from %lld repeats\n",
			  min( u64ResTD14, u64TimeIndexTD14 ), max( u64ResTD14, u64TimeIndexTD14 ), u64TimeIndexTD14 );
	printf( "Thread 15 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD15, u64TimeIndexTD15 ), max( u64ResTD15, u64TimeIndexTD15 ), u64TimeIndexTD15 );
	printf( "Thread 16 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD16, u64TimeIndexTD16 ), max( u64ResTD16, u64TimeIndexTD16 ), u64TimeIndexTD16 );
	printf( "Thread 17 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD17, u64TimeIndexTD17 ), max( u64ResTD17, u64TimeIndexTD17 ), u64TimeIndexTD17 );
	printf( "Thread 18 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD18, u64TimeIndexTD18 ), max( u64ResTD18, u64TimeIndexTD18 ), u64TimeIndexTD18 );
	printf( "Thread 19 execution time min = %lld max = %lld from %lld repeats\n",
				min( u64ResTD19, u64TimeIndexTD19 ), max( u64ResTD19, u64TimeIndexTD19 ), u64TimeIndexTD19 );


	fp = fopen( "TESTID_3.txt", "w" );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD0, u64TimeIndexTD0 ), max( u64ResTD0, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD1, u64TimeIndexTD1 ), max( u64ResTD1, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD2, u64TimeIndexTD2 ), max( u64ResTD2, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD3, u64TimeIndexTD3 ), max( u64ResTD3, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD4, u64TimeIndexTD4 ), max( u64ResTD4, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD5, u64TimeIndexTD5 ), max( u64ResTD5, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD6, u64TimeIndexTD6 ), max( u64ResTD6, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD7, u64TimeIndexTD7 ), max( u64ResTD7, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD8, u64TimeIndexTD8 ), max( u64ResTD8, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD9, u64TimeIndexTD9 ), max( u64ResTD9, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD10, u64TimeIndexTD10 ), max( u64ResTD10, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD11, u64TimeIndexTD11 ), max( u64ResTD11, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD12, u64TimeIndexTD12 ), max( u64ResTD12, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD13, u64TimeIndexTD13 ), max( u64ResTD13, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD14, u64TimeIndexTD14 ), max( u64ResTD14, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD15, u64TimeIndexTD15 ), max( u64ResTD15, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD16, u64TimeIndexTD16 ), max( u64ResTD16, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD17, u64TimeIndexTD17 ), max( u64ResTD17, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD18, u64TimeIndexTD18 ), max( u64ResTD18, SIZE_OF_REPEATS ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD19, u64TimeIndexTD19 ), max( u64ResTD19, SIZE_OF_REPEATS ) );

	fclose( fp );

	return 0;
}
