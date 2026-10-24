#include "types.h"

extern "C" void func_004AC770(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DA5C8;

struct func_0056DFB8_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_0056DFB8(struct func_0056DFB8_arg0 *arg0, s32 arg1) {
    arg0->unk8 = &D_005DA5C8;
    func_004AC770(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
