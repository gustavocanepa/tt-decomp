#include "types.h"

struct Struct_00370D98 {
    char pad0[0x4C];
    s32 unk4C;
};

extern "C" void func_00319728(Struct_00370D98 *arg0, f32 fparg0) {
    arg0->unk4C = (s32)(fparg0 * 100.0f);
}
