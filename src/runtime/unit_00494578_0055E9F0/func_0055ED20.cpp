#include "types.h"

extern "C" void DynamicsConductor__structor_1(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D6710;

struct func_0055ED20_arg0 {
    char pad0[0x241CC];
    void *unk241CC;
};

extern "C" void func_0055ED20(struct func_0055ED20_arg0 *arg0, s32 arg1) {
    arg0->unk241CC = &D_005D6710;
    DynamicsConductor__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
