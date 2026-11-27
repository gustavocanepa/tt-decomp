#include "types.h"

struct Inner {
    char pad0[0x18];
    char *f18;
};

struct S {
    char pad0[4];
    s32 f4;
    s32 f8;
    char pad1[0xD8 - 0x0C];
    Inner *fD8;
    s32 fDC;
    char pad2[0xE4 - 0xE0];
    s32 fE4;
};

extern "C" void func_003013F0(char *arg0);
extern "C" s32 func_002E3A60(s32 arg0, s32 arg1, s32 arg2);
extern "C" void func_0043C0D8(s32 arg0, float f);

extern "C" void func_0037A670(S *arg0, s32 arg1) {
    s32 s1;

    if (arg0->fDC != 0) {
        if (arg0->f4 != 0) {
            func_0043C0D8(arg0->f4, 0.016666666f);
        }
        s1 = 0;
        if (arg0->f8 != 0) {
            s1 = func_002E3A60(arg0->f8, arg0->f4, arg1);
        }
        if (arg0->fDC != 0) {
            if (arg0->fE4 == 0) {
                if (s1 != 0) {
                    func_003013F0(arg0->fD8->f18);
                }
            }
        }
        arg0->fE4 = (arg0->fE4 != 0) | (s1 != 0);
    }
}
