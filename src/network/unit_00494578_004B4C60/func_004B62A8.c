/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F46A0(s32, s32, s32);   /* extern */

extern char D_00774200[];
void func_004B62A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_004F46A0((s32)D_00774200, 1, 0);
}
