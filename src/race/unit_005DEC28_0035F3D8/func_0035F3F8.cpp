#include "types.h"

struct Obj003A8380 {
    char pad0[0x72];
    s16 unk7A;
};

extern "C" void func_0035F3F8(struct Obj003A8380 *arg0, f32 fparg0) {
    arg0->unk7A = (s32)(fparg0 + 0.5f);
}
