#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <inttypes.h>
#include <sched.h>
#include "config.h"
#include "utility.h"
#include "testcase.h"

extern int sched_getcpu(void);

pthread_t pthrd_ID[TEST_THREADS];

char cArrTD0[SIZE_10MB]      = {0};
uint64_t u64ResTD0[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD0     = 0;
uint8_t u8ErrorStatusTD0     = FAILURE;

char cArrTD1[SIZE_10MB]      = {0};
uint64_t u64ResTD1[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD1     = 0;
uint8_t u8ErrorStatusTD1     = FAILURE;

char cArrTD2[SIZE_10MB]      = {0};
uint64_t u64ResTD2[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD2     = 0;
uint8_t u8ErrorStatusTD2     = FAILURE;

char cArrTD3[SIZE_10MB]      = {0};
uint64_t u64ResTD3[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD3     = 0;
uint8_t u8ErrorStatusTD3     = FAILURE;

char cArrTD4[SIZE_10MB]      = {0};
uint64_t u64ResTD4[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD4     = 0;
uint8_t u8ErrorStatusTD4     = FAILURE;

char cArrTD5[SIZE_10MB]      = {0};
uint64_t u64ResTD5[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD5     = 0;
uint8_t u8ErrorStatusTD5     = FAILURE;

char cArrTD6[SIZE_10MB]      = {0};
uint64_t u64ResTD6[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD6     = 0;
uint8_t u8ErrorStatusTD6     = FAILURE;

char cArrTD7[SIZE_10MB]      = {0};
uint64_t u64ResTD7[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD7     = 0;
uint8_t u8ErrorStatusTD7     = FAILURE;

char cArrTD8[SIZE_10MB]      = {0};
uint64_t u64ResTD8[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD8     = 0;
uint8_t u8ErrorStatusTD8     = FAILURE;

char cArrTD9[SIZE_10MB]      = {0};
uint64_t u64ResTD9[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD9     = 0;
uint8_t u8ErrorStatusTD9     = FAILURE;

char cArrTD10[SIZE_10MB]      = {0};
uint64_t u64ResTD10[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD10     = 0;
uint8_t u8ErrorStatusTD10     = FAILURE;

char cArrTD11[SIZE_10MB]      = {0};
uint64_t u64ResTD11[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD11     = 0;
uint8_t u8ErrorStatusTD11     = FAILURE;

char cArrTD12[SIZE_10MB]      = {0};
uint64_t u64ResTD12[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD12     = 0;
uint8_t u8ErrorStatusTD12     = FAILURE;

char cArrTD13[SIZE_10MB]      = {0};
uint64_t u64ResTD13[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD13     = 0;
uint8_t u8ErrorStatusTD13     = FAILURE;

char cArrTD14[SIZE_10MB]      = {0};
uint64_t u64ResTD14[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD14     = 0;
uint8_t u8ErrorStatusTD14     = FAILURE;

char cArrTD15[SIZE_10MB]      = {0};
uint64_t u64ResTD15[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD15     = 0;
uint8_t u8ErrorStatusTD15     = FAILURE;

char cArrTD16[SIZE_10MB]      = {0};
uint64_t u64ResTD16[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD16     = 0;
uint8_t u8ErrorStatusTD16     = FAILURE;

char cArrTD17[SIZE_10MB]      = {0};
uint64_t u64ResTD17[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD17     = 0;
uint8_t u8ErrorStatusTD17     = FAILURE;

char cArrTD18[SIZE_10MB]      = {0};
uint64_t u64ResTD18[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD18     = 0;
uint8_t u8ErrorStatusTD18     = FAILURE;

char cArrTD19[SIZE_10MB]      = {0};
uint64_t u64ResTD19[SIZE_1MB] = {0};
uint64_t u64TimeIndexTD19     = 0;
uint8_t u8ErrorStatusTD19     = FAILURE;



void* TD0( void* argt )
{
	uint32_t iTestSuitID;
	uint64_t u64Index;
	HRTime timeStart;
	HRTime timeEnd;
	HRTime timeDiff;
	uint64_t u64TimeInSecs    = 0;
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 0 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD0 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD0[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

							if( u64TimeIndexTD0  < SIZE_OF_REPEATS )
							{
									/* Calculate time difference */
									timeDiff      = diff( timeStart, timeEnd );
									u64TimeInSecs = timeDiff.tv_sec*(1E9) + timeDiff.tv_nsec;
									u64ResTD0[u64TimeIndexTD0] = u64TimeInSecs;
							}
							else
							{
									 printf( "Breaking off TD0\n" );

									 /* Check array contents for integrity */
									 for(u64Index = 0; u64Index < SIZE_10MB; u64Index++)
									 {
												if( 'A' != cArrTD0[u64Index] )
												{
														printf( "%sTD0 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD0[u64Index],KWHT );
														u8ErrorStatusTD0 = FAILURE;
														break;
												}
												else
												{
														u8ErrorStatusTD0 = NEUTRAL;
												}
									 }
									 /* Check the error state and decide for success */
									 if( NEUTRAL == u8ErrorStatusTD0 )
									 {
										 		printf( "%sTD0 Success\n%s",KGRN, KWHT );
												u8ErrorStatusTD0 = SUCCESS;
									 }

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
	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 1 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD1 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD1[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
								 /* Check array contents for integrity */
								 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
								 {
											if( 'A' != cArrTD1[u64Index] )
											{
													printf( "%sTD1 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD1[u64Index], KWHT );
													u8ErrorStatusTD1 = FAILURE;
													break;
											}
											else
											{
													u8ErrorStatusTD1 = NEUTRAL;
											}
								 }
								 /* Check the error state and decide for success */
								 if( NEUTRAL == u8ErrorStatusTD1 )
								 {
									 		printf( "%sTD1 Success\n%s",KGRN, KWHT );
											u8ErrorStatusTD1 = SUCCESS;
								 }
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 2 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD2 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD2[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD2[u64Index] )
											 {
												 	 printf( "%sTD2 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD2[u64Index], KWHT );
													 u8ErrorStatusTD2 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD2 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD2 )
									{
											 printf( "%sTD2 Success\n%s",KGRN, KWHT );
											 u8ErrorStatusTD2 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 3 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD3 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD3[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD3[u64Index] )
											 {
												 	 printf( "%sTD3 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD3[u64Index], KWHT );
													 u8ErrorStatusTD3 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD3 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD3 )
									{
											 printf( "%sTD3 Success\n%s",KGRN, KWHT );
											 u8ErrorStatusTD3 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 4 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD4 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD4[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD4[u64Index] )
											 {
												 	 printf( "%sTD4 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD4[u64Index], KWHT );
													 u8ErrorStatusTD4 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD4 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD4 )
									{
											 printf( "%sTD4 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD4 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 5 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD5 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD5[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
								 /* Check array contents for integrity */
								 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
								 {
											if( 'A' != cArrTD5[u64Index] )
											{
													printf( "%sTD5 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD5[u64Index], KWHT );
													u8ErrorStatusTD5 = FAILURE;
													break;
											}
											else
											{
													u8ErrorStatusTD5 = NEUTRAL;
											}
								 }
								 /* Check the error state and decide for success */
								 if( NEUTRAL == u8ErrorStatusTD5 )
								 {
											printf( "%sTD5 Success%s\n",KGRN,KWHT );
											u8ErrorStatusTD5 = SUCCESS;
								 }
								 break;
							}
							u64TimeIndexTD5++;
				 }
				 break;

			default:
				 break;
		}

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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 6 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD6 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
									 cArrTD6[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									 /* Check array contents for integrity */
									 for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									 {
												if( 'A' != cArrTD6[u64Index] )
												{
														printf( "%sTD6 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD6[u64Index], KWHT );
														u8ErrorStatusTD6 = FAILURE;
														break;
												}
												else
												{
														u8ErrorStatusTD6 = NEUTRAL;
												}
									 }
									 /* Check the error state and decide for success */
									 if( NEUTRAL == u8ErrorStatusTD6 )
									 {
												printf( "%sTD6 Success%s\n",KGRN,KWHT );
												u8ErrorStatusTD6 = SUCCESS;
									 }
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 7 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD7 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
		       				cArrTD7[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD7[u64Index] )
											 {
													 printf( "%sTD7 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD7[u64Index], KWHT );
													 u8ErrorStatusTD7 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD7 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD7 )
									{
											 printf( "%sTD7 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD7 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 8 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD8 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD8[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD8[u64Index] )
											 {
													 printf( "%sTD8 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD8[u64Index], KWHT );
													 u8ErrorStatusTD8 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD8 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD8 )
									{
											 printf( "%sTD8 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD8 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 9 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD9 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for(u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD9[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD9[u64Index] )
											 {
													 printf( "%sTD9 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD9[u64Index], KWHT );
													 u8ErrorStatusTD9 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD9 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD9 )
									{
											 printf( "%sTD9 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD9 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 10 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD10 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD10[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD10[u64Index] )
											 {
													 printf( "%sTD10 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD10[u64Index], KWHT );
													 u8ErrorStatusTD10 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD10 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD10 )
									{
											 printf( "%sTD10 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD10 = SUCCESS;
									}
								 	break;
							}
							u64TimeIndexTD10++;
				 }
				 break;

			default:
				 break;
		}

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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 11 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD11 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD11[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD11[u64Index] )
											 {
													 printf( "%sTD11 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD11[u64Index], KWHT );
													 u8ErrorStatusTD11 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD11 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD11 )
									{
											 printf( "%sTD11 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD11 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 12 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD12 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD12[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD12[u64Index] )
											 {
													 printf( "%sTD12 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD12[u64Index], KWHT );
													 u8ErrorStatusTD12 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD12 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD12 )
									{
											 printf( "%sTD12 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD12 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 13 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD13 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD13[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD13[u64Index] )
											 {
													 printf( "%sTD13 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD13[u64Index], KWHT );
													 u8ErrorStatusTD13 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD13 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD13 )
									{
											 printf( "%sTD13 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD13 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 14 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD14 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD14[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD14[u64Index] )
											 {
													 printf( "%sTD14 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD14[u64Index], KWHT );
													 u8ErrorStatusTD14 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD14 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD14 )
									{
											 printf( "%sTD14 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD14 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 15 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD15 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD15[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD15[u64Index] )
											 {
													 printf( "%sTD15 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD15[u64Index], KWHT );
													 u8ErrorStatusTD15 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD15 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD15 )
									{
											 printf( "%sTD15 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD15 = SUCCESS;
									}
								 	break;
							}
							u64TimeIndexTD15++;
				 }
				 break;

			default:
				 break;
		}

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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 16 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD16 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD16[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD16[u64Index] )
											 {
													 printf( "%sTD16 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD16[u64Index], KWHT );
													 u8ErrorStatusTD16 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD16 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD16 )
									{
											 printf( "%sTD16 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD16 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 17 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD17 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD17[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD17[u64Index] )
											 {
													 printf( "%sTD17 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD17[u64Index], KWHT );
													 u8ErrorStatusTD17 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD17 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD17 )
									{
											 printf( "%sTD17 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD17 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 18 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD18 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
									cArrTD18[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD18[u64Index] )
											 {
													 printf( "%sTD18 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD18[u64Index], KWHT );
													 u8ErrorStatusTD18 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD18 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD18 )
									{
											 printf( "%sTD18 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD18 = SUCCESS;
									}
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

	int inCpu = 0;

	inCpu = sched_getcpu();

	printf( "PThread 19 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

	iTestSuitID = *( (int*)argt );

	switch( iTestSuitID )
	{
			case TESTID_CACHE_INITTEST:
				 u64TimeIndexTD19 = 0;
				 while( 1 )
				 {
						 	/* Do INITTEST testsuit */
							clock_gettime( CLOCK_REALTIME, &timeStart );
						 	for( u64Index = 0 ; u64Index < SIZE_10MB; u64Index++ )
						 	{
		       				cArrTD19[u64Index] = 'A';
		   				}
						 	clock_gettime( CLOCK_REALTIME, &timeEnd );

							usleep( 1 );

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
									/* Check array contents for integrity */
									for( u64Index = 0; u64Index < SIZE_10MB; u64Index++ )
									{
											 if( 'A' != cArrTD19[u64Index] )
											 {
													 printf( "%sTD19 Failure( At index %lld value is 0x%x)%s\n", KRED,u64Index, cArrTD19[u64Index], KWHT );
													 u8ErrorStatusTD19 = FAILURE;
													 break;
											 }
											 else
											 {
													 u8ErrorStatusTD19 = NEUTRAL;
											 }
									}
									/* Check the error state and decide for success */
									if( NEUTRAL == u8ErrorStatusTD19 )
									{
											 printf( "%sTD19 Success%s\n",KGRN,KWHT );
											 u8ErrorStatusTD19 = SUCCESS;
									}
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
	j = TESTID_CACHE_INITTEST;

	printf( "%s",KWHT );
	printf( "************Test Case ID %d************\n", j );

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
			sleep(1);
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


	fp = fopen( "TESTID_0.txt", "w" );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD0, u64TimeIndexTD0 ), max( u64ResTD0, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD1, u64TimeIndexTD1 ), max( u64ResTD1, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD2, u64TimeIndexTD2 ), max( u64ResTD2, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD3, u64TimeIndexTD3 ), max( u64ResTD3, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD4, u64TimeIndexTD4 ), max( u64ResTD4, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD5, u64TimeIndexTD5 ), max( u64ResTD5, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD6, u64TimeIndexTD6 ), max( u64ResTD6, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD7, u64TimeIndexTD7 ), max( u64ResTD7, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD8, u64TimeIndexTD8 ), max( u64ResTD8, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD9, u64TimeIndexTD9 ), max( u64ResTD9, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD10, u64TimeIndexTD10 ), max( u64ResTD10, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD11, u64TimeIndexTD11 ), max( u64ResTD11, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD12, u64TimeIndexTD12 ), max( u64ResTD12, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD13, u64TimeIndexTD13 ), max( u64ResTD13, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD14, u64TimeIndexTD14 ), max( u64ResTD14, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD15, u64TimeIndexTD15 ), max( u64ResTD15, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD16, u64TimeIndexTD16 ), max( u64ResTD16, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD17, u64TimeIndexTD17 ), max( u64ResTD17, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD18, u64TimeIndexTD18 ), max( u64ResTD18, SIZE_1MB ) );
	fprintf( fp, "Min %lld Max %lld\n", min( u64ResTD19, u64TimeIndexTD19 ), max( u64ResTD19, SIZE_1MB ) );
	fclose( fp );

	return 0;
}
