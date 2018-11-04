#ifndef __USERTYPES_H_
#define __USERTYPED_H_

#include <time.h>
#include <inttypes.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <semaphore.h>
#include "config.h"

typedef void*(*FP_Thrd)(void*);
typedef struct timespec HRTime;
typedef struct sStackProfile
{
	uint64_t u64StackLowerLimit_TD0;
	uint64_t u64StackUpperLimit_TD0;
	uint64_t u64StackLowerLimit_TD1;
	uint64_t u64StackUpperLimit_TD1;
	uint64_t u64StackLowerLimit_TD2;
	uint64_t u64StackUpperLimit_TD2;
	uint64_t u64StackLowerLimit_TD3;
	uint64_t u64StackUpperLimit_TD3;
	uint64_t u64StackLowerLimit_TD4;
	uint64_t u64StackUpperLimit_TD4;
	uint64_t u64StackLowerLimit_TD5;
	uint64_t u64StackUpperLimit_TD5;
	uint64_t u64StackLowerLimit_TD6;
	uint64_t u64StackUpperLimit_TD6;
	uint64_t u64StackLowerLimit_TD7;
	uint64_t u64StackUpperLimit_TD7;
	uint64_t u64StackLowerLimit_TD8;
	uint64_t u64StackUpperLimit_TD8;
	uint64_t u64StackLowerLimit_TD9;
	uint64_t u64StackUpperLimit_TD9;
	uint64_t u64StackLowerLimit_TD10;
	uint64_t u64StackUpperLimit_TD10;
	uint64_t u64StackLowerLimit_TD11;
	uint64_t u64StackUpperLimit_TD11;
	uint64_t u64StackLowerLimit_TD12;
	uint64_t u64StackUpperLimit_TD12;
	uint64_t u64StackLowerLimit_TD13;
	uint64_t u64StackUpperLimit_TD13;
	uint64_t u64StackLowerLimit_TD14;
	uint64_t u64StackUpperLimit_TD14;
	uint64_t u64StackLowerLimit_TD15;
	uint64_t u64StackUpperLimit_TD15;
	uint64_t u64StackLowerLimit_TD16;
	uint64_t u64StackUpperLimit_TD16;
	uint64_t u64StackLowerLimit_TD17;
	uint64_t u64StackUpperLimit_TD17;
	uint64_t u64StackLowerLimit_TD18;
	uint64_t u64StackUpperLimit_TD18;
	uint64_t u64StackLowerLimit_TD19;
	uint64_t u64StackUpperLimit_TD19;
	uint8_t  u8TD0Done;
	uint8_t  u8TD1Done;
	uint8_t  u8TD2Done;
	uint8_t  u8TD3Done;
	uint8_t  u8TD4Done;
	uint8_t  u8TD5Done;
	uint8_t  u8TD6Done;
	uint8_t  u8TD7Done;
	uint8_t  u8TD8Done;
	uint8_t  u8TD9Done;
	uint8_t  u8TD10Done;
	uint8_t  u8TD11Done;
	uint8_t  u8TD12Done;
	uint8_t  u8TD13Done;
	uint8_t  u8TD14Done;
	uint8_t  u8TD15Done;
	uint8_t  u8TD16Done;
	uint8_t  u8TD17Done;
	uint8_t  u8TD18Done;
	uint8_t  u8TD19Done;
}Stack;

typedef struct hHeapProfile
{
	void* pTD0[TOTAL_PAGES];
	void* pTD1[TOTAL_PAGES];
	void* pTD2[TOTAL_PAGES];
	void* pTD3[TOTAL_PAGES];
	void* pTD4[TOTAL_PAGES];
	void* pTD5[TOTAL_PAGES];
	void* pTD6[TOTAL_PAGES];
	void* pTD7[TOTAL_PAGES];
	void* pTD8[TOTAL_PAGES];
	void* pTD9[TOTAL_PAGES];
	void* pTD10[TOTAL_PAGES];
	void* pTD11[TOTAL_PAGES];
	void* pTD12[TOTAL_PAGES];
	void* pTD13[TOTAL_PAGES];
	void* pTD14[TOTAL_PAGES];
	void* pTD15[TOTAL_PAGES];
	void* pTD16[TOTAL_PAGES];
	void* pTD17[TOTAL_PAGES];
	void* pTD18[TOTAL_PAGES];
	void* pTD19[TOTAL_PAGES];
	uint64_t u64TD0HeapMemory;
	uint64_t u64TD1HeapMemory;
	uint64_t u64TD2HeapMemory;
	uint64_t u64TD3HeapMemory;
	uint64_t u64TD4HeapMemory;
	uint64_t u64TD5HeapMemory;
	uint64_t u64TD6HeapMemory;
	uint64_t u64TD7HeapMemory;
	uint64_t u64TD8HeapMemory;
	uint64_t u64TD9HeapMemory;
	uint64_t u64TD10HeapMemory;
	uint64_t u64TD11HeapMemory;
	uint64_t u64TD12HeapMemory;
	uint64_t u64TD13HeapMemory;
	uint64_t u64TD14HeapMemory;
	uint64_t u64TD15HeapMemory;
	uint64_t u64TD16HeapMemory;
	uint64_t u64TD17HeapMemory;
	uint64_t u64TD18HeapMemory;
	uint64_t u64TD19HeapMemory;
	uint8_t  u8TD0Complete;
	uint8_t  u8TD1Complete;
	uint8_t  u8TD2Complete;
	uint8_t  u8TD3Complete;
	uint8_t  u8TD4Complete;
	uint8_t  u8TD5Complete;
	uint8_t  u8TD6Complete;
	uint8_t  u8TD7Complete;
	uint8_t  u8TD8Complete;
	uint8_t  u8TD9Complete;
	uint8_t  u8TD10Complete;
	uint8_t  u8TD11Complete;
	uint8_t  u8TD12Complete;
	uint8_t  u8TD13Complete;
	uint8_t  u8TD14Complete;
	uint8_t  u8TD15Complete;
	uint8_t  u8TD16Complete;
	uint8_t  u8TD17Complete;
	uint8_t  u8TD18Complete;
	uint8_t  u8TD19Complete;
	uint8_t  u8TD0HeapInit;
	uint8_t  u8TD1HeapInit;
	uint8_t  u8TD2HeapInit;
	uint8_t  u8TD3HeapInit;
	uint8_t  u8TD4HeapInit;
	uint8_t  u8TD5HeapInit;
	uint8_t  u8TD6HeapInit;
	uint8_t  u8TD7HeapInit;
	uint8_t  u8TD8HeapInit;
	uint8_t  u8TD9HeapInit;
	uint8_t  u8TD10HeapInit;
	uint8_t  u8TD11HeapInit;
	uint8_t  u8TD12HeapInit;
	uint8_t  u8TD13HeapInit;
	uint8_t  u8TD14HeapInit;
	uint8_t  u8TD15HeapInit;
	uint8_t  u8TD16HeapInit;
	uint8_t  u8TD17HeapInit;
	uint8_t  u8TD18HeapInit;
	uint8_t  u8TD19HeapInit;
	uint8_t  u8TD0ModificationComplete;
}Heap;

typedef struct stStatus
{
	uint8_t  u8TD0Complete;
	uint8_t  u8TD1Complete;
	uint8_t  u8TD2Complete;
	uint8_t  u8TD3Complete;
	uint8_t  u8TD4Complete;
	uint8_t  u8TD5Complete;
	uint8_t  u8TD6Complete;
	uint8_t  u8TD7Complete;
	uint8_t  u8TD8Complete;
	uint8_t  u8TD9Complete;
	uint8_t  u8TD10Complete;
	uint8_t  u8TD11Complete;
	uint8_t  u8TD12Complete;
	uint8_t  u8TD13Complete;
	uint8_t  u8TD14Complete;
	uint8_t  u8TD15Complete;
	uint8_t  u8TD16Complete;
	uint8_t  u8TD17Complete;
	uint8_t  u8TD18Complete;
	uint8_t  u8TD19Complete;
}ThreadStatus;

typedef struct stFifo
{
		const char* fifoName;
		mode_t fifoPermissions;
		/* DIR0 - From Thread A -> Thread B */
		HRTime startTime_DIR0;
		HRTime endTime_DIR0;
		uint8_t u8TransferComplete_DIR0;
		/* DIR1 - From Thread B -> Thread A */
		HRTime startTime_DIR1;
		HRTime endTime_DIR1;
		uint8_t u8TransferComplete_DIR1;
		/* Mutex to synchronize both the threads */
		sem_t mutex;
}Fifo;

#endif
