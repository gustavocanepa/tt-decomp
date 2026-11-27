#include "types.h"

struct Struct_00384908 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
};

extern "C" void func_0032DCC0(Struct_00384908 *arg0, f32 fparg0) {
    arg0->unk4 = 0;
    f32 result = fparg0 * 115.0f;
    arg0->unk0 = 0;
    arg0->unk8 = 0;
    arg0->unkC = result;
}
