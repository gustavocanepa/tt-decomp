#include "types.h"

struct S0036FF78 {
    char pad0[0xC];
    f32 unkC;
    char pad1[0x1C - 0xC - 4];
    f32 unk1C;
};

extern "C" f32 func_00318908(S0036FF78 *arg0, f32 fparg0) {
    return (arg0->unk1C * fparg0) / arg0->unkC;
}
