#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003BDB88(void *, s32);                 /* extern */
s32 func_003BDBC0(void *, s32, s32, s32, s32);  /* extern */

void func_003BC878(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s8 sp[0x10];
    func_003BDB88(sp, arg4 + 0x3B04);
    func_003BDBC0(sp, arg0, arg1, arg2, arg3);
}
