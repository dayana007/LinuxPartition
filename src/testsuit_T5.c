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
const uint8_t cu8CompareBuffer[PAGE_SIZE] = {0};
Heap hProfVar = {0};

void* TD0( void* argt )
{
		uint64_t u64Index = 0;
		printf( "PThread 0 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD0HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD0[hProfVar.u64TD0HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD0[hProfVar.u64TD0HeapMemory] )
				{
						/* Memory Tracker */
						hProfVar.u64TD0HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD0HeapMemory )
		{
				memset( hProfVar.pTD0[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD0HeapInit = 1;

		/*
			Sleep here until all the threads have initialized their heaps
			5 seconds is more than enough time for this
		*/
		sleep( 5 );

		/* Change the buffer */
		memset( hProfVar.pTD0[0], 'A', PAGE_SIZE );
		printf( "Thread TD0 heap buffer contents modification complete\n" );
		hProfVar.u8TD0ModificationComplete = 1;

		hProfVar.u8TD0Complete = 1;
		return (void*)NULL;
}

void* TD1( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 1 started with Test ID %d\n", *( (int*)argt ) );

	  /* Find total pages on heap availiable to this thread */
	  while( hProfVar.u64TD1HeapMemory < TOTAL_PAGES )
	  {
		  	hProfVar.pTD1[hProfVar.u64TD1HeapMemory] = malloc( PAGE_SIZE );
			  if( NULL != hProfVar.pTD1[hProfVar.u64TD1HeapMemory] )
			  {
				  	/* Memory Tracker */
					  hProfVar.u64TD1HeapMemory++;
			  }
	  }

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD1HeapMemory )
		{
				memset( hProfVar.pTD1[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD1HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD1HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD1[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD1 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD1 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD1 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD1Complete = 1;
	  return (void*)NULL;
}

void* TD2( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 2 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD2HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD2[hProfVar.u64TD2HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD2[hProfVar.u64TD2HeapMemory] )
				{
						/* Memory Tracker */
						hProfVar.u64TD2HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD2HeapMemory )
		{
				memset( hProfVar.pTD2[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD2HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD2HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD2[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD2 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD2 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD2 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD2Complete = 1;
		return (void*)NULL;
}

void* TD3( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 3 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD3HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD3[hProfVar.u64TD3HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD3[hProfVar.u64TD3HeapMemory] )
				{
						/* Memory Tracker */
						hProfVar.u64TD3HeapMemory++;
					}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD3HeapMemory )
		{
				memset( hProfVar.pTD3[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD3HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD3HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD3[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD3 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD3 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD3 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD3Complete = 1;
		return (void*)NULL;
}

void* TD4( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 4 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD4HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD4[hProfVar.u64TD4HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD4[hProfVar.u64TD4HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD4HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD4HeapMemory )
		{
				memset( hProfVar.pTD4[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD4HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD4HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD4[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD4 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD4 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD4 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD4Complete = 1;
		return (void*)NULL;
}

void* TD5( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 5 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD5HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD5[hProfVar.u64TD5HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD5[hProfVar.u64TD5HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD5HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD5HeapMemory )
		{
				memset( hProfVar.pTD5[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD5HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD5HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD5[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD5 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD5 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD5 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD5Complete = 1;
		return (void*)NULL;
}

void* TD6( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 6 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD6HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD6[hProfVar.u64TD6HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD6[hProfVar.u64TD6HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD6HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD6HeapMemory )
		{
				memset( hProfVar.pTD6[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD6HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD6HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD6[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD6 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD6 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD6 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD6Complete = 1;
		return (void*)NULL;
}

void* TD7( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 7 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD7HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD7[hProfVar.u64TD7HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD7[hProfVar.u64TD7HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD7HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD7HeapMemory )
		{
				memset( hProfVar.pTD7[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD7HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD7HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD7[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD7 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD7 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD7 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD7Complete = 1;
		return (void*)NULL;
}

void* TD8( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 8 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD8HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD8[hProfVar.u64TD8HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD8[hProfVar.u64TD8HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD8HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD8HeapMemory )
		{
			memset( hProfVar.pTD8[u64Index], 0, PAGE_SIZE );
			u64Index++;
		}
		hProfVar.u8TD8HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD8HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD8[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD8 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD8 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD8 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD8Complete = 1;
		return (void*)NULL;
}

void* TD9( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 9 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD9HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD9[hProfVar.u64TD9HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD9[hProfVar.u64TD9HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD9HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD9HeapMemory )
		{
				memset( hProfVar.pTD9[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD9HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD9HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD9[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD9 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD9 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD9 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD9Complete = 1;
		return (void*)NULL;
}

void* TD10( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 10 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD10HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD10[hProfVar.u64TD10HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD10[hProfVar.u64TD10HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD10HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD10HeapMemory )
		{
				memset( hProfVar.pTD10[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD10HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD10HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD10[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD10 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD10 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD10 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD10Complete = 1;
		return (void*)NULL;
}

void* TD11( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 11 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD11HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD11[hProfVar.u64TD11HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD11[hProfVar.u64TD11HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD11HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD11HeapMemory )
		{
				memset( hProfVar.pTD11[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD11HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD11HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD11[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD11 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD11 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD11 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD11Complete = 1;
		return (void*)NULL;
}

void* TD12( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 12 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD12HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD12[hProfVar.u64TD12HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD12[hProfVar.u64TD12HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD12HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD12HeapMemory )
		{
				memset( hProfVar.pTD12[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD12HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD12HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD12[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD12 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD12 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD12 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD12Complete = 1;
		return (void*)NULL;
}

void* TD13( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 13 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD13HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD13[hProfVar.u64TD13HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD13[hProfVar.u64TD13HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD13HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD13HeapMemory )
		{
				memset( hProfVar.pTD13[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD13HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD13HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD13[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD13 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD13 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD13 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD13Complete = 1;
		return (void*)NULL;
}

void* TD14( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 14 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD14HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD14[hProfVar.u64TD14HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD14[hProfVar.u64TD14HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD14HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD14HeapMemory )
		{
				memset( hProfVar.pTD14[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD14HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD14HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD14[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD14 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD14 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD14 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD14Complete = 1;
		return (void*)NULL;
}

void* TD15( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 15 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD15HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD15[hProfVar.u64TD15HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD15[hProfVar.u64TD15HeapMemory] )
				{
					/* Memory Tracker */
					hProfVar.u64TD15HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD15HeapMemory )
		{
				memset( hProfVar.pTD15[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD15HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD15HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD15[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD15 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD15 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD15 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD15Complete = 1;
		return (void*)NULL;
}

void* TD16( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 16 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD16HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD16[hProfVar.u64TD16HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD16[hProfVar.u64TD16HeapMemory] )
				{
						/* Memory Tracker */
						hProfVar.u64TD16HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD16HeapMemory )
		{
				memset( hProfVar.pTD16[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD16HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD16HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD16[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD16 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD16 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD16 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD16Complete = 1;
		return (void*)NULL;
}

void* TD17( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 17 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD17HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD17[hProfVar.u64TD17HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD17[hProfVar.u64TD17HeapMemory] )
				{
						/* Memory Tracker */
						hProfVar.u64TD17HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD17HeapMemory )
		{
				memset( hProfVar.pTD17[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD17HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD17HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD17[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD17 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD17 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD17 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD17Complete = 1;
		return (void*)NULL;
}

void* TD18( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 18 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD18HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD18[hProfVar.u64TD18HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD18[hProfVar.u64TD18HeapMemory] )
				{
						/* Memory Tracker */
						hProfVar.u64TD18HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD18HeapMemory )
		{
				memset( hProfVar.pTD18[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD18HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD18HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD18[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD18 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD18 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD18 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD18Complete = 1;
		return (void*)NULL;
}

void* TD19( void* argt )
{
		uint8_t  u8Res    = 0;
		uint64_t u64Index = 0;
		printf( "PThread 19 started with Test ID %d\n", *( (int*)argt ) );

		/* Find total pages on heap availiable to this thread */
		while( hProfVar.u64TD19HeapMemory < TOTAL_PAGES )
		{
				hProfVar.pTD19[hProfVar.u64TD19HeapMemory] = malloc( PAGE_SIZE );
				if( NULL != hProfVar.pTD19[hProfVar.u64TD19HeapMemory] )
				{
						/* Memory Tracker */
						hProfVar.u64TD19HeapMemory++;
				}
		}

		/* Initilize the heap with a pattern */
		while( u64Index < hProfVar.u64TD19HeapMemory )
		{
				memset( hProfVar.pTD19[u64Index], 0, PAGE_SIZE );
				u64Index++;
		}
		hProfVar.u8TD19HeapInit = 1;

		/* Wait until the heap allocated buffer in thread 0 is modified */
		while( 0 == hProfVar.u8TD0ModificationComplete )
		{
				usleep( 1 );
		}

		/* Check the buffer contents to see if they have changed */
		u64Index = 0;
		while( u64Index < hProfVar.u64TD19HeapMemory )
		{
				if( 0 != memcmp( ( void* )hProfVar.pTD19[u64Index], ( void* )cu8CompareBuffer, PAGE_SIZE ) )
				{
						printf( "Thread TD19 heap buffer %d contents have changed!\n", u64Index );
						u8Res++;
				}
				u64Index++;
		}

		/* Notice for failures and report them and their count */
		if( 0 == u8Res )
		{
				printf( "Thread TD19 heap segregation test success\n");
		}
		else
		{
				printf( "Thread TD19 heap segregation failed at %d different heap allocations\n", u8Res );
		}

		hProfVar.u8TD19Complete = 1;
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
	j = TESTID_HEAPTEST;

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
			usleep( 1 );
			if( hProfVar.u8TD0Complete == 1 )
			{
				   if( hProfVar.u8TD1Complete == 1 )
					 {
						   if( hProfVar.u8TD2Complete == 1 )
							 {
								   if( hProfVar.u8TD3Complete == 1 )
									 {
												if( hProfVar.u8TD4Complete == 1 )
												{
														if( hProfVar.u8TD5Complete == 1 )
														{
																if( hProfVar.u8TD6Complete == 1 )
																{
																		if( hProfVar.u8TD7Complete == 1 )
																		{
																				if( hProfVar.u8TD8Complete == 1 )
																				{
																						if( hProfVar.u8TD9Complete == 1 )
																						{
																								if( hProfVar.u8TD10Complete == 1 )
																								{
																									  if( hProfVar.u8TD11Complete == 1 )
																										{
																											  if( hProfVar.u8TD12Complete == 1 )
																												{
																														if( hProfVar.u8TD13Complete == 1 )
																														{
																																if( hProfVar.u8TD14Complete == 1 )
																																{
																																		if( hProfVar.u8TD15Complete == 1 )
																																		{
																																				if( hProfVar.u8TD16Complete == 1 )
																																				{
																																						if( hProfVar.u8TD17Complete == 1 )
																																						{
																																								if( hProfVar.u8TD18Complete == 1 )
																																								{
																																										if( hProfVar.u8TD19Complete == 1 )
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

	fp = fopen( "TESTID_4.txt", "w" );
	/* fprintf( fp, "Min %lu Max %lu\n", stStackVar.u64StackLowerLimit_TD0, stStackVar.u64StackUpperLimit_TD0  ); */
	fclose( fp );

	return 0;
}
