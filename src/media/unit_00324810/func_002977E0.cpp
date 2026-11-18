#include "types.h"

struct Tmp { s32 field0; char pad[0xC]; };

extern "C" void func_00292AF8(Tmp *arg0);
extern "C" void func_002914B8(s32 *arg0, s32 arg1, s32 arg2);
extern "C" void func_00290478(Tmp *arg0, s32 arg1);
extern "C" void func_00296A20(s32 *arg0, s32 arg1);

extern "C" s32 func_002977E0(void) {
    s32 result;
    Tmp tmp;
    Tmp *p = &tmp;

    func_00292AF8(p);
    s32 v = p->field0;
    func_002914B8(&result, v, 1);
    func_00290478(p, 2);
    s32 r = result;
    func_00296A20(&result, 2);
    return r;
}
