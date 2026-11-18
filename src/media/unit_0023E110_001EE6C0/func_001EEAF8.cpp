#include "types.h"

struct S {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_001EECC0(struct S *arg0);
extern "C" void func_00266228(s32 arg0);
extern "C" void func_0042BE30(void);

extern "C" void func_001EEAF8(struct S *arg0) {
    struct S *s0 = arg0;
    func_001EECC0(s0);
    func_00266228(s0->unk10);
    func_0042BE30();
}
