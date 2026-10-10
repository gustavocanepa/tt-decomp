#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00323950(s32 arg0, s32 arg1) {
    return *(s32 *)(0x583D88 + (((u32) (arg0 + arg1) % 12U) * 4));
}
