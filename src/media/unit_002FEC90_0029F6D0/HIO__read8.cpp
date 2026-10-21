#include "types.h"

extern "C" void func_0029F6A0(void *arg0, u8 *arg1, s32 arg2);

extern "C" u8 HIO__read8(void *arg0) {
    u8 local;
    func_0029F6A0(arg0, &local, 1);
    return local;
}
