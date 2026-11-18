#include "types.h"

extern "C" void func_0041E8D0(f32 *a, f32 *b);

extern "C" f32 func_0041E9D0(f32 a, f32 b, f32 t) {
    func_0041E8D0(&a, &b);
    return a * t + b * (0x1.000000p+0f - t);
}
