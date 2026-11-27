#include "types.h"

extern void *D_005C9098;
extern "C" void func_004B57A8(void *, float);
extern "C" void func_003402F0(void *, s32);
extern "C" void func_0050E1A8(void *);

struct RaceBGMPS2__structor_1_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void RaceBGMPS2__structor_1(struct RaceBGMPS2__structor_1_arg0 *arg0, s32 arg1) {
    arg0->unk4 = &D_005C9098;
    func_004B57A8(arg0, 1.0000000298f);
    func_003402F0(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
