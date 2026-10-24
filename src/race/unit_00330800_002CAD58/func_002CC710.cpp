#include "types.h"

struct RS {
    char pad[0x21C];
    f32 f12C;
};

extern "C" s32 func_00477D28(void *a0, void *a1, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16);
extern "C" void func_00370BE8(void *self, s32 inner, s32 outer, f32 innerRadius, f32 outerRadius);

extern "C" void func_002CC710(void *arg0, void *arg1) {
    f32 t = ((RS *)arg0)->f12C;
    if (0.0f < t) {
        s32 r = func_00477D28(arg0, arg1, 0.0f, 0.0f, 0.0f, t * 0.7f * 0.01f, 255.0f);
        func_00370BE8(arg1, r, 0, 420.0f, 200.0f);
    }
}
