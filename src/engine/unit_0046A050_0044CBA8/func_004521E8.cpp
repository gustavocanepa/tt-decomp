#include "types.h"
extern "C" void func_004A6328(f32, f32 *, f32 *);
extern "C" void func_004521E8(f32 *out, f32 a, f32 b) {
    f32 s[4];
    f32 x = a * 0.5f;
    f32 y = b * 0.5f;
    func_004A6328(x, &s[0], &s[1]);
    func_004A6328(y, &s[2], &s[3]);
    out[0] = s[0] * s[3];
    out[1] = s[0] * s[2];
    out[2] = s[1] * s[2];
    out[3] = s[1] * s[3];
}
