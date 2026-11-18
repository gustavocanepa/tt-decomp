#include "types.h"

extern "C" void func_0050A480(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_0050AD20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf[4];
    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = arg2;
    buf[3] = arg3;
    func_0050A480(buf, arg1, arg2, arg3);
}
