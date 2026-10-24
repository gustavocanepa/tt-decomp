#include "types.h"

struct func_00287A08_arg0 {
    char pad0[0x3E4];
    s32 unk3AC;
    s32 unk3B0;
    char pad3B4[0xC];
    s32 unk3C0;
    s32 unk3C4;
};

extern "C" s32 func_00287A08(struct func_00287A08_arg0 *arg0, s32 arg1) {
    s32 a3 = 0;
    s32 v0 = arg0->unk3AC - arg0->unk3C0;
    v0 = v0 - arg0->unk3B0;

    if (v0 > 0) {
        if (arg1 < v0) {
            arg0->unk3C0 = arg0->unk3C0 + arg1;
        } else {
            arg0->unk3C0 = arg0->unk3C0 + v0;
        }
        arg0->unk3C4 = 1;
        a3 = 1;
    }
    return a3;
}
