#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA550(s32, s32);                /* extern */
s32 func_004FB3D0(s32);                     /* extern */

extern char D_005A30CC[];
extern char D_0078C254[];
void func_004FD6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_004FB3D0(5);
    func_004FA550(5, *(s32 *)D_0078C254);
    *(s32 *)D_005A30CC = 0;
}
