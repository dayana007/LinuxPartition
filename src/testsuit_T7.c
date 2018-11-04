#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <inttypes.h>
#include <sched.h>
#include <semaphore.h>
#include <sys/sysinfo.h>
#include "config.h"
#include "utility.h"
#include "testcase.h"

extern int sched_getcpu(void);

pthread_t pthrd_ID[TEST_THREADS_SCHED];
uint8_t u8Core[TOTAL_CORE] = {0};
sem_t mutex;

void* TD0( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 0 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD1( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 1 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD2( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 2 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD3( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 3 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD4( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 4 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD5( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 5 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD6( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 6 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD7( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 7 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD8( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 8 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD9( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 9 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD10( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 10 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD11( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 11 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD12( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 12 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD13( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 13 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD14( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 14 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD15( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 15 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD16( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 16 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD17( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 17 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD18( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 18 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD19( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 19 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD20( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 20 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD21( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 21 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD22( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 22 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD23( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 23 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD24( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 24 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD25( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 25 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD26( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 26 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD27( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 27 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD28( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 28 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD29( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 29 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD30( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 30 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD31( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 31 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD32( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 32 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD33( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 33 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD34( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 34 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD35( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 35 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD36( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 36 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD37( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 37 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD38( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 38 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD39( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 39 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD40( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 40 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD41( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 41 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD42( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 42 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD43( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 43 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD44( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 44 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD45( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 45 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD46( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 46 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD47( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 47 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD48( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 48 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD49( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 49 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD50( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 50 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD51( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 51 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD52( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 52 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD53( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 53 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD54( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 54 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD55( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 55 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD56( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 56 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD57( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 57 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD58( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 58 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD59( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 59 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD60( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 60 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD61( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 61 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD62( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 62 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD63( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 63 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD64( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 64 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD65( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 65 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD66( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 66 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD67( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 67 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD68( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 68 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD69( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 69 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD70( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 70 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD71( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 71 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD72( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 72 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD73( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 73 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD74( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 74 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD75( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 75 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD76( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 76 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD77( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 77 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD78( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 78 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD79( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 79 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD80( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 80 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD81( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 81 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD82( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 82 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD83( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 83 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD84( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 84 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD85( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 85 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD86( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 86 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD87( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 87 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD88( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 88 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD89( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 89 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD90( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 90 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD91( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 91 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD92( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 92 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD93( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 93 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD94( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 94 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD95( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 95 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD96( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 96 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD97( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 97 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD98( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 98 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

void* TD99( void* argt )
{
    int inCpu = sched_getcpu();
    printf( "PThread 99 started with Test ID %d running on CPU %d\n", *( (int*)argt ), inCpu );

    sem_wait(&mutex);
    u8Core[inCpu]++;
    sem_post(&mutex);

    return (void*)NULL;
}

FP_Thrd fpArr[TEST_THREADS_SCHED] = {
			TD0, TD1, TD2, TD3, TD4, TD5, TD6, TD7, TD8, TD9,
      TD10, TD11, TD12, TD13, TD14, TD15, TD16, TD17, TD18, TD19,
      TD20, TD21, TD22, TD23, TD24, TD25, TD26, TD27, TD28, TD29,
      TD30, TD31, TD32, TD33, TD34, TD35, TD36, TD37, TD38, TD39,
      TD40, TD41, TD42, TD43, TD44, TD45, TD46, TD47, TD48, TD49,
      TD50, TD51, TD52, TD53, TD54, TD55, TD56, TD57, TD58, TD59,
      TD60, TD61, TD62, TD63, TD64, TD65, TD66, TD67, TD68, TD69,
      TD70, TD71, TD72, TD73, TD74, TD75, TD76, TD77, TD78, TD79,
      TD80, TD81, TD82, TD83, TD84, TD85, TD86, TD87, TD88, TD89,
      TD90, TD91, TD92, TD93, TD94, TD95, TD96, TD97, TD98, TD99
		};



int main( int argc, char** argv )
{
	int i;
	int j;
	int err;
	int iRes;
	void* result = (void*)&iRes;
  FILE *fp;
  const uint8_t coreCount = get_nprocs();

	printf( "************Test Case ID %d************\n", j );
  printf( "This system has %d processors configured and %d processors available.\n", get_nprocs_conf(), get_nprocs() );
  sem_init(&mutex, 0, 1);

	/* Test suite run */
	for( i = 0; i < TEST_THREADS_SCHED; i++ )
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
	for( i = 0; i < TEST_THREADS_SCHED; i++ )
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

  fp = fopen( "TESTID_7.txt", "w" );
  for( i = 0; i < coreCount; i++ )
  {
      printf( "Core : %d Utilization : %d \n", i, u8Core[i] );
      fprintf( fp, "Core %d Percent %d\n", i, u8Core[i] );
  }
  fclose( fp );

  sem_destroy(&mutex);

	return 0;
}
