#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004BE938(s32, s32, s32, s32, s32, s32);  /* extern */

extern char D_00776D80[];
void func_004BEAF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_004BE938((s32)D_00776D80, 3, arg0, arg1, arg2, arg3);
}
