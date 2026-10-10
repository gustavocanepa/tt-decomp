#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A53A8(s32 arg0) {
    s32 temp_v0;

    temp_v0 = arg0 & 0xFF;
    return ((((arg0 >> 8) & 0xFFFF) ^ *(s32 *)(0x773A10 + (temp_v0 * 4))) != 0) ? -1 : temp_v0;
}
