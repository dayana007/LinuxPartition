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


pthread_t pthrd_ID[5];
Stack stStackVar;

void vRecurseTD0( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD1( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD2( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD3( int64_t u64Parameter, uint8_t u8Thread );
void vRecurseTD4( int64_t u64Parameter, uint8_t u8Thread );

void* TD0( void* argt )
{
	printf( "PThread 0 started with Test ID %d\n", *( (int*)argt ) );

	while( 1 )
	{
		stStackVar.u64StackLowerLimit_TD0 = getStackPointer();
		vRecurseTD0( 1000,0 );
		usleep(1);
	}
}

void* TD1( void* argt )
{
	printf( "PThread 1 started with Test ID %d\n", *( (int*)argt ) );

	while( 1 )
	{
		stStackVar.u64StackLowerLimit_TD1 = getStackPointer();
		vRecurseTD1( 3000,1 );
		usleep(1);
	}
}

void* TD2( void* argt )
{
	printf( "PThread 2 started with Test ID %d\n", *( (int*)argt ) );

	while( 1 )
	{
		stStackVar.u64StackLowerLimit_TD2 = getStackPointer();
		vRecurseTD2( 4000,2 );
		usleep(1);
	}
}

void* TD3( void* argt )
{
	printf( "PThread 3 started with Test ID %d\n", *( (int*)argt ) );

	while( 1 )
	{
		stStackVar.u64StackLowerLimit_TD3 = getStackPointer();
		vRecurseTD3( 5000,3 );
		usleep(1);
	}
}

void* TD4( void* argt )
{
	printf( "PThread 4 started with Test ID %d\n", *( (int*)argt ) );

	while( 1 )
	{
		stStackVar.u64StackLowerLimit_TD4 = getStackPointer();
		vRecurseTD4( 6000,4 );
		usleep(1);
	}
}

FP_Thrd fpArr[TEST_THREADS] = {
			TD0,
			TD1,
			TD2,
			TD3,
			TD4
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

int main( int argc, char** argv )
{
	int i;
	int j;
	int err;
	int iRes;
	void* result = (void*)&iRes;
	j = TESTID_STACKTEST_VARYINGSIZES;

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
	sleep(5);
	/* Trigger via IPC to trigger application loop stop in secure partition in Pike OS */

	/* Clean up threads for the next test suit run*/
	for( i = 0; i < TEST_THREADS; i++ )
	{
		if( SUCCESS != pthread_cancel( pthrd_ID[i] ) )
		{
			printf( "pthread_cancel() on pthread %d failed, may be thread is already terminated\n", i );
			if( SUCCESS != pthread_join( pthrd_ID[i], &result ) )
				printf( "pthread_join() on pthread %d failed\n", i );
		}
		else
		{
			if( SUCCESS != pthread_join( pthrd_ID[i], &result ) )
				printf( "pthread_join() on pthread %d failed\n", i );
		}
	}


	printf( "Thread 0 stack min stack max, diff = %lx %lx %lu\n",
        stStackVar.u64StackLowerLimit_TD0,
        stStackVar.u64StackUpperLimit_TD0,
 	stStackVar.u64StackLowerLimit_TD0 - stStackVar.u64StackUpperLimit_TD0  );

	printf( "Thread 1 stack min stack max, diff = %lx %lx %lu\n",
        stStackVar.u64StackLowerLimit_TD1,
        stStackVar.u64StackUpperLimit_TD1,
	stStackVar.u64StackLowerLimit_TD1 - stStackVar.u64StackUpperLimit_TD1  );

	printf( "Thread 2 stack min stack max, diff = %lx %lx %lu\n",
        stStackVar.u64StackLowerLimit_TD2,
        stStackVar.u64StackUpperLimit_TD2,
	stStackVar.u64StackLowerLimit_TD2 - stStackVar.u64StackUpperLimit_TD2 );

	printf( "Thread 3 stack min stack max, diff = %lx %lx %lu\n",
        stStackVar.u64StackLowerLimit_TD3,
        stStackVar.u64StackUpperLimit_TD3,
	stStackVar.u64StackLowerLimit_TD3 - stStackVar.u64StackUpperLimit_TD3 );

	printf( "Thread 4 stack min stack max, diff = %lx %lx %lu\n",
        stStackVar.u64StackLowerLimit_TD4,
        stStackVar.u64StackUpperLimit_TD4,
	stStackVar.u64StackLowerLimit_TD4 - stStackVar.u64StackUpperLimit_TD4 );

	#if 0
	fp = fopen( "TESTID_3.txt", "w" );
	fprintf( fp, "Min %lu Max %lu\n", min( u64ResTD0, u64TimeIndexTD0 ), max( u64ResTD0, SIZE_1MB ) );
	fprintf( fp, "Min %lu Max %lu\n", min( u64ResTD1, u64TimeIndexTD1 ), max( u64ResTD1, SIZE_1MB ) );
	fprintf( fp, "Min %lu Max %lu\n", min( u64ResTD2, u64TimeIndexTD2 ), max( u64ResTD2, SIZE_1MB ) );
	fprintf( fp, "Min %lu Max %lu\n", min( u64ResTD3, u64TimeIndexTD3 ), max( u64ResTD3, SIZE_1MB ) );
	fprintf( fp, "Min %lu Max %lu\n", min( u64ResTD4, u64TimeIndexTD4 ), max( u64ResTD4, SIZE_1MB ) );
	fclose( fp );

	#endif

	return 0;
}
