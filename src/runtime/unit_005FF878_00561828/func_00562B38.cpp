#include "types.h"

struct Obj;

extern "C" void func_003FDC30(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_00562B38(Obj *arg0, s32 arg1) {
    func_003FDC30(arg0, 0x400, arg1 > 0);
}
