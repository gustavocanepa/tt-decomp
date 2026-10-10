#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F6678(s32, s32, s32);   /* extern */

extern char D_00769D28[];
s32 func_0041F810(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_004F6678((s32)D_00769D28, 0, 0x40);
    return 1;
}
