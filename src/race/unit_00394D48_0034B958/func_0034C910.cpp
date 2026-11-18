#include "types.h"

struct Obj {
    char pad[0x54];
    s32 unk54;
};

extern "C" void func_0034C9A0(void *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4);

extern "C" void func_0034C910(struct Obj *arg0) {
    func_0034C9A0(arg0, arg0->unk54, -1, 1.0f, 1000.0f);
}
