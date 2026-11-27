#include "types.h"

struct S00480F78;

extern "C" void func_00447D00(struct S00480F78 *arg0, s32 arg1);

extern "C" s32 *func_002D6C58(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, struct S00480F78 *arg4) {
    func_00447D00(arg4, arg3);
    *arg0 = 1;
    return arg0;
}
