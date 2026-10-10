#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00411990(s32, s32, s32, s32);          /* extern */
s32 func_004A8368(s32);                             /* extern */

void func_00411A58(s32 arg0, s32 arg1, s32 arg2) {
    func_00411990(arg0, arg1, arg2, func_004A8368(arg1));
}
