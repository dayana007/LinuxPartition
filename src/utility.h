#ifndef __UTILITY_H_
#define __UTILITY_H_

#include "usertypes.h"

HRTime diff( HRTime start, HRTime end);
uint64_t max( uint64_t a[], uint64_t num_elements );
uint64_t min( uint64_t a[], uint64_t num_elements );
uint8_t u8Architecture_BitSize(void);
uint64_t getStackPointer(void);

#endif
