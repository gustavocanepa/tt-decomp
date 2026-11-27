#include "types.h"

struct S004CFA28 {
    char pad0[0x14];
    void (*unk14)(s32 arg0);
};

extern "C" void func_0048D0E0(struct S004CFA28 *arg0, s32 arg1) {
    arg0->unk14(arg1);
}
