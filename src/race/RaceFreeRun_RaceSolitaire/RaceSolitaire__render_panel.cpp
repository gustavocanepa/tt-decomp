#include "types.h"

struct Inner003EB718 {
    char pad0[0xE0];
    s32 unkE0;
};

struct Obj003EB718 {
    char pad0[0x6C];
    Inner003EB718 *unk6C;
};

extern "C" void func_0033DD40(Obj003EB718 *arg0);

extern "C" void RaceSolitaire__render_panel(Obj003EB718 *arg0) {
    if (arg0->unk6C->unkE0 == 0) {
        return func_0033DD40(arg0);
    }
}
