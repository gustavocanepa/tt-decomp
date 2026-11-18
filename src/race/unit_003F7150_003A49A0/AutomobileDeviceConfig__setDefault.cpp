#include "types.h"

struct Obj_003F7160;

extern "C" void func_003A4980(s16 *arg0, s16 arg1);
extern "C" s32 func_003A4990(struct Obj_003F7160 *arg0, s16 arg1);

extern "C" s32 AutomobileDeviceConfig__setDefault(struct Obj_003F7160 *arg0) {
    struct Obj_003F7160 *s0 = arg0;

    func_003A4980((s16 *)s0, 1);
    return func_003A4990(s0, 1);
}
