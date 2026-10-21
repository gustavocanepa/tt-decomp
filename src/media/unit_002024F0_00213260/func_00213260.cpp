#include "types.h"

struct Color4f {
    f32 r;
    f32 g;
    f32 b;
    f32 a;
};

extern "C" void func_00213260(Color4f *out, u32 c) {
    u32 sh8 = c >> 8;
    u32 sh16 = c >> 16;
    s32 b3 = (s32)(c >> 24);
    c &= 0xFF;
    s32 b0 = (s32)c;
    s32 b1 = (s32)(sh8 & 0xFF);
    s32 b2 = (s32)(sh16 & 0xFF);
    out->r = (f32)b0 / 255.0f;
    out->g = (f32)b1 / 255.0f;
    out->b = (f32)b2 / 255.0f;
    out->a = (f32)b3 / 255.0f;
}
