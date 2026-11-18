#include "types.h"

extern "C" void func_0028FA68(s32 *arg0, s32 arg1);

extern "C" s32 func_00290400(s32 arg0, s32 arg1) {
    s32 local = arg1;

    func_0028FA68(&local, arg0);
    return local;
}
