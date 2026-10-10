/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003FC7D8(s32);                         /* extern */

extern char D_005857DC[];
void func_003FC8A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_003FC7D8(M2C_FIELD(*(void **)D_005857DC, s32 *, 0x68C));
}
