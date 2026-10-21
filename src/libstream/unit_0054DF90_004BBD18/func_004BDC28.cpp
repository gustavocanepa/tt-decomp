#include "types.h"

struct S0054FE78 {
    char pad0[0x38];
    s32 unk38;
};

extern "C" void func_004FA830(s32 arg0);

extern "C" void func_004BDC28(S0054FE78 *arg0) {
    func_004FA830(arg0->unk38);
}
