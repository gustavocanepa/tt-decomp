#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA850(s32);                         /* extern */

s32 func_004FBAD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_004FA850(arg3);
    __asm__ volatile("sync.l");
    __asm__ volatile("ei");
    return 0;
}
