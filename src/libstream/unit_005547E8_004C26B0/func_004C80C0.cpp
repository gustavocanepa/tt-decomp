#include "types.h"

struct S0055D528 {
    char pad0[0x1C];
    char unk1C;
};

extern "C" s32 func_004C8310(S0055D528 *arg0, s32 arg1);

extern "C" s32 func_004C80C0(S0055D528 *arg0) {
    arg0->unk1C = 0;
    return func_004C8310(arg0, 0);
}
