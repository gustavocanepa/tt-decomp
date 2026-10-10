#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_005857DC[];
void func_0011C830(s32 arg0, s8 arg1) {
    M2C_FIELD(*(void **)D_005857DC, s8 *, 0x1D92) = arg1;
}
