#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <inttypes.h>
#include "config.h"
#include "utility.h"
#include "testcase.h"


pthread_t pthrd_ID[TEST_THREADS];
Stack stStackVar;

void vRecurseTD0( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD1( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD2( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD3( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD4( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD5( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD6( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD7( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD8( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD9( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD10( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD11( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD12( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD13( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD14( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD15( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD16( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD17( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD18( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD19( int64_t u64Parameter, uint8_t u8Thread );

void* TD0( void* argt )
{
		printf( "PThread 0 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD0 = getStackPointer();
		vRecurseTD0( STACK_DEPTH,0 );
		stStackVar.u8TD0Done = 1;
		return (void*)NULL;
}

void* TD1( void* argt )
{
		printf( "PThread 1 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD1 = getStackPointer();
		vRecurseTD1( STACK_DEPTH,1 );
		stStackVar.u8TD1Done = 1;
		return (void*)NULL;
}

void* TD2( void* argt )
{
		printf( "PThread 2 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD2 = getStackPointer();
		vRecurseTD2( STACK_DEPTH,2 );
		stStackVar.u8TD2Done = 1;
		return (void*)NULL;
}

void* TD3( void* argt )
{
		printf( "PThread 3 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD3 = getStackPointer();
		vRecurseTD3( STACK_DEPTH,3 );
		stStackVar.u8TD3Done = 1;
		return (void*)NULL;
}

void* TD4( void* argt )
{
		printf( "PThread 4 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD4 = getStackPointer();
		vRecurseTD4( STACK_DEPTH,4 );
		stStackVar.u8TD4Done = 1;
		return (void*)NULL;
}

void* TD5( void* argt )
{
		printf( "PThread 5 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD5 = getStackPointer();
		vRecurseTD5( STACK_DEPTH,5 );
		stStackVar.u8TD5Done = 1;
		return (void*)NULL;
}

void* TD6( void* argt )
{
		printf( "PThread 6 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD6 = getStackPointer();
		vRecurseTD6( STACK_DEPTH,6 );
		stStackVar.u8TD6Done = 1;
		return (void*)NULL;
}

void* TD7( void* argt )
{
		printf( "PThread 7 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD7 = getStackPointer();
		vRecurseTD7( STACK_DEPTH,7 );
		stStackVar.u8TD7Done = 1;
		return (void*)NULL;
}

void* TD8( void* argt )
{
		printf( "PThread 8 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD8 = getStackPointer();
		vRecurseTD8( STACK_DEPTH,8 );
		stStackVar.u8TD8Done = 1;
		return (void*)NULL;
}

void* TD9( void* argt )
{
		printf( "PThread 9 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD9 = getStackPointer();
		vRecurseTD9( STACK_DEPTH,9 );
		stStackVar.u8TD9Done = 1;
		return (void*)NULL;
}

void* TD10( void* argt )
{
		printf( "PThread 10 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD10 = getStackPointer();
		vRecurseTD10( STACK_DEPTH,10 );
		stStackVar.u8TD10Done = 1;
		return (void*)NULL;
}

void* TD11( void* argt )
{
		printf( "PThread 11 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD11 = getStackPointer();
		vRecurseTD11( STACK_DEPTH,11 );
		stStackVar.u8TD11Done = 1;
		return (void*)NULL;
}

void* TD12( void* argt )
{
		printf( "PThread 12 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD12 = getStackPointer();
		vRecurseTD12( STACK_DEPTH,12 );
		stStackVar.u8TD12Done = 1;
		return (void*)NULL;
}

void* TD13( void* argt )
{
		printf( "PThread 13 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD13 = getStackPointer();
		vRecurseTD13( STACK_DEPTH,13 );
		stStackVar.u8TD13Done = 1;
		return (void*)NULL;
}

void* TD14( void* argt )
{
		printf( "PThread 14 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD14 = getStackPointer();
		vRecurseTD14( STACK_DEPTH,14 );
		stStackVar.u8TD14Done = 1;
		return (void*)NULL;
}

void* TD15( void* argt )
{
		printf( "PThread 15 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD15 = getStackPointer();
		vRecurseTD15( STACK_DEPTH,15 );
		stStackVar.u8TD15Done = 1;
		return (void*)NULL;
}

void* TD16( void* argt )
{
		printf( "PThread 16 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD16 = getStackPointer();
		vRecurseTD16( STACK_DEPTH,16 );
		stStackVar.u8TD16Done = 1;
		return (void*)NULL;
}

void* TD17( void* argt )
{
		printf( "PThread 17 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD17 = getStackPointer();
		vRecurseTD17( STACK_DEPTH,17 );
		stStackVar.u8TD17Done = 1;
		return (void*)NULL;
}

void* TD18( void* argt )
{
		printf( "PThread 18 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD18 = getStackPointer();
		vRecurseTD18( STACK_DEPTH,18 );
		stStackVar.u8TD18Done = 1;
		return (void*)NULL;
}

void* TD19( void* argt )
{
	  printf( "PThread 19 started with Test ID %d\n", *( (int*)argt ) );
		stStackVar.u64StackLowerLimit_TD19 = getStackPointer();
		vRecurseTD19( STACK_DEPTH,19 );
		stStackVar.u8TD19Done = 1;
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

void vRecurseTD0( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD0( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD0 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD1( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD1( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD1 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD2( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD2( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD2 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD3( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD3( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD3 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD4( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD4( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD4 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD5( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD5( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD5 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD6( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD6( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD6 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD7( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD7( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD7 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD8( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD8( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD8 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD9( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD9( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD9 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD10( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD10( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD10 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD11( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD11( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD11 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD12( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD12( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD12 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD13( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD13( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD13 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD14( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD14( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD14 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD15( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD15( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD15 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD16( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD16( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD16 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD17( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD17( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD17 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD18( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD18( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD18 = getStackPointer();
		}
		return;
	}
}

void vRecurseTD19( int64_t u64Parameter, uint8_t u8Thread )
{
	if( u64Parameter > 0 )
	{
		u64Parameter--;
		vRecurseTD19( u64Parameter, u8Thread );
	}
	else
	{
		if( u64Parameter == 0 )
		{
			stStackVar.u64StackUpperLimit_TD19 = getStackPointer();
			return;
		}

	}
}

int main( int argc, char** argv )
{
	int i;
	int j;
	int err;
	FILE *fp;
	j = TESTID_STACKTEST_SCHEDPOINT_1;

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
			if( stStackVar.u8TD0Done == 1 )
			{
				if( stStackVar.u8TD1Done == 1 )
				{
					if( stStackVar.u8TD2Done == 1 )
					{
						if( stStackVar.u8TD3Done == 1 )
						{
							if( stStackVar.u8TD4Done == 1 )
							{
								if( stStackVar.u8TD5Done == 1 )
								{
									if( stStackVar.u8TD6Done == 1 )
									{
										if( stStackVar.u8TD7Done == 1 )
										{
											if( stStackVar.u8TD8Done == 1 )
											{
												if( stStackVar.u8TD9Done == 1 )
												{
													if( stStackVar.u8TD10Done == 1 )
													{
														if( stStackVar.u8TD11Done == 1 )
														{
															if( stStackVar.u8TD12Done == 1 )
															{
																if( stStackVar.u8TD13Done == 1 )
																{
																	if( stStackVar.u8TD14Done == 1 )
																	{
																		if( stStackVar.u8TD15Done == 1 )
																		{
																			if( stStackVar.u8TD16Done == 1 )
																			{
																				if( stStackVar.u8TD17Done == 1 )
																				{
																					if( stStackVar.u8TD18Done == 1 )
																					{
																						if( stStackVar.u8TD19Done == 1 )
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
			usleep( 1 );
	}
	/* Trigger via IPC to trigger application loop stop in secure partition in Pike OS */

	printf( "Thread 0 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD0, stStackVar.u64StackUpperLimit_TD0 );
	printf( "Thread 1 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD1, stStackVar.u64StackUpperLimit_TD1 );
	printf( "Thread 2 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD2, stStackVar.u64StackUpperLimit_TD2 );
	printf( "Thread 3 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD3, stStackVar.u64StackUpperLimit_TD3 );
	printf( "Thread 4 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD4, stStackVar.u64StackUpperLimit_TD4 );
	printf( "Thread 5 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD5, stStackVar.u64StackUpperLimit_TD5 );
	printf( "Thread 6 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD6, stStackVar.u64StackUpperLimit_TD6 );
	printf( "Thread 7 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD7, stStackVar.u64StackUpperLimit_TD7 );
	printf( "Thread 8 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD8, stStackVar.u64StackUpperLimit_TD8 );
	printf( "Thread 9 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD9, stStackVar.u64StackUpperLimit_TD9 );
	printf( "Thread 10 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD10, stStackVar.u64StackUpperLimit_TD10 );
	printf( "Thread 11 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD11, stStackVar.u64StackUpperLimit_TD11 );
	printf( "Thread 12 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD12, stStackVar.u64StackUpperLimit_TD12 );
	printf( "Thread 13 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD13, stStackVar.u64StackUpperLimit_TD13 );
	printf( "Thread 14 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD14, stStackVar.u64StackUpperLimit_TD14 );
	printf( "Thread 15 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD15, stStackVar.u64StackUpperLimit_TD15 );
	printf( "Thread 16 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD16, stStackVar.u64StackUpperLimit_TD16 );
	printf( "Thread 17 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD17, stStackVar.u64StackUpperLimit_TD17 );
	printf( "Thread 18 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD18, stStackVar.u64StackUpperLimit_TD18 );
	printf( "Thread 19 stack min stack max = 0x%lx 0x%lx\n", stStackVar.u64StackLowerLimit_TD19, stStackVar.u64StackUpperLimit_TD19 );

	/* Check if each thread consumes the same amout of stack */
	printf( "Thread 0 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD0 - stStackVar.u64StackUpperLimit_TD0 ) );
	printf( "Thread 1 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD1 - stStackVar.u64StackUpperLimit_TD1 ) );
	printf( "Thread 2 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD2 - stStackVar.u64StackUpperLimit_TD2 ) );
	printf( "Thread 3 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD3 - stStackVar.u64StackUpperLimit_TD3 ) );
	printf( "Thread 4 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD4 - stStackVar.u64StackUpperLimit_TD4 ) );
	printf( "Thread 5 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD5 - stStackVar.u64StackUpperLimit_TD5 ) );
	printf( "Thread 6 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD6 - stStackVar.u64StackUpperLimit_TD6 ) );
	printf( "Thread 7 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD7 - stStackVar.u64StackUpperLimit_TD7 ) );
	printf( "Thread 8 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD8 - stStackVar.u64StackUpperLimit_TD8 ) );
	printf( "Thread 9 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD9 - stStackVar.u64StackUpperLimit_TD9 ) );
	printf( "Thread 10 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD10 - stStackVar.u64StackUpperLimit_TD10 ) );
	printf( "Thread 11 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD11 - stStackVar.u64StackUpperLimit_TD11 ) );
	printf( "Thread 12 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD12 - stStackVar.u64StackUpperLimit_TD12 ) );
	printf( "Thread 13 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD13 - stStackVar.u64StackUpperLimit_TD13 ) );
	printf( "Thread 14 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD14 - stStackVar.u64StackUpperLimit_TD14 ) );
	printf( "Thread 15 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD15 - stStackVar.u64StackUpperLimit_TD15 ) );
	printf( "Thread 16 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD16 - stStackVar.u64StackUpperLimit_TD16 ) );
	printf( "Thread 17 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD17 - stStackVar.u64StackUpperLimit_TD17 ) );
	printf( "Thread 18 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD18 - stStackVar.u64StackUpperLimit_TD18 ) );
	printf( "Thread 19 consumes 0x%lx bytes\n", ( stStackVar.u64StackLowerLimit_TD19 - stStackVar.u64StackUpperLimit_TD19 ) );

	fp = fopen( "TESTID_4.txt", "w" );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD0, stStackVar.u64StackUpperLimit_TD0  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD1, stStackVar.u64StackUpperLimit_TD1  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD2, stStackVar.u64StackUpperLimit_TD2  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD3, stStackVar.u64StackUpperLimit_TD3  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD4, stStackVar.u64StackUpperLimit_TD4  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD5, stStackVar.u64StackUpperLimit_TD5  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD6, stStackVar.u64StackUpperLimit_TD6  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD7, stStackVar.u64StackUpperLimit_TD7  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD8, stStackVar.u64StackUpperLimit_TD8  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD9, stStackVar.u64StackUpperLimit_TD9  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD10, stStackVar.u64StackUpperLimit_TD10  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD11, stStackVar.u64StackUpperLimit_TD11  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD12, stStackVar.u64StackUpperLimit_TD12  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD13, stStackVar.u64StackUpperLimit_TD13  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD14, stStackVar.u64StackUpperLimit_TD14  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD15, stStackVar.u64StackUpperLimit_TD15  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD16, stStackVar.u64StackUpperLimit_TD16  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD17, stStackVar.u64StackUpperLimit_TD17  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD18, stStackVar.u64StackUpperLimit_TD18  );
	fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD19, stStackVar.u64StackUpperLimit_TD19  );
	fclose( fp );

	return 0;
}
