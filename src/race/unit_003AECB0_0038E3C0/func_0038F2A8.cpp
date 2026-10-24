#include "types.h"

extern "C" void func_0038F210(f32, f32, f32, f32);

extern "C" void func_0038F2A8(s32 x, s32 y, s32 w, s32 h) {
    func_0038F210((f32)x, (f32)y, (f32)(x + w), (f32)(y + h));
}
