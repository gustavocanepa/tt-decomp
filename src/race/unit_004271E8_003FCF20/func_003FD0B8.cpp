#include "types.h"
struct T { s32 arr[1][2]; };
extern T D_00585640;
extern "C" void func_003FD0B8(s32 i, s32 *p, s32 *q) {
    *p = D_00585640.arr[i][0];
    *q = D_00585640.arr[i][1];
}
