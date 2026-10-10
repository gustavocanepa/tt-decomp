#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00779E84[];
u16 func_004C9418(s32 arg0, s32 arg1) {
    return *(s32 *)(D_00779E84 + (((arg0 * 0x1A) + arg1) * 2));
}
