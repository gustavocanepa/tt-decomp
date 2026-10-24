#include "types.h"

struct Obj00305590 {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_002B1070(s32 arg0);

extern "C" void hModule__setName(struct Obj00305590 *arg0, s32 arg1) {
    s32 local;
    s32 *s0 = &arg0->unk10;

    local = func_002B1070(arg1);
    if (s0 != &local) {
        *s0 = local;
    }
}
