#include "types.h"

struct Obj003A8380 {
    char pad0[0x7E];
    s16 unk7A;
};

extern "C" void func_0035D4F0(struct Obj003A8380 *arg0, f32 fparg0) {
    arg0->unk7A = (s32)(fparg0 + 0.5f);
}
