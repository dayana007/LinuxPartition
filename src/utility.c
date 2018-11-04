#include "utility.h"
#include <stdint.h>

HRTime diff( HRTime start, HRTime end)
{
        HRTime temp;
        if ((end.tv_nsec-start.tv_nsec)<0)
        {
                temp.tv_sec  = end.tv_sec-start.tv_sec-1;
                temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
        }
        else
        {
                temp.tv_sec  = end.tv_sec-start.tv_sec;
                temp.tv_nsec = end.tv_nsec-start.tv_nsec;
        }
        return temp;
}

uint64_t max( uint64_t a[], uint64_t num_elements )
{
	uint64_t i;
	uint64_t maxi = a[0];

   	for ( i = 1; i < num_elements; i++ )
   	{
		if (a[i] > maxi)
	 	{
	    		maxi = a[i];
	 	}
   	}

   	return maxi;
}

uint64_t min( uint64_t a[], uint64_t num_elements )
{
	uint64_t i;
	uint64_t mini = a[0];
	for( i = 1; i < num_elements; i++ )
	{
		if( a[i] < mini )
		{
			mini = a[i];
		}
	}

	return mini;
}

uint8_t u8Architecture_BitSize(void)
{
    if ((size_t)-1 > 0xffffffffUL)
    {
        return 1; /* 64 bit processor*/
    }
    else
    {
        return 0;/* 32 bit processor */
    }
}

uint64_t getStackPointer()
{
   uint64_t sp;
   #if defined(__x86_64__)
       asm( "mov %%rsp, %0" : "=rm" ( sp ) );
   #elif defined(__i386__)
	     asm ("movl %%esp, %0" : "=r" ( sp ) );
   #endif

  return sp;
}
