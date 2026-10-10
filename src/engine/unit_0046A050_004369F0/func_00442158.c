#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00447540(s32);
void func_00447D00(s32, s32);
s32 *func_00442158(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00447D00(arg3, arg2);
    func_00447540(arg1);
    *arg0 = 1;
    return arg0;
}
