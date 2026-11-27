#include "types.h"

extern "C" void AutomaticFader__oneshot(s32 arg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4);

extern "C" void func_00355698(s32 arg0) {
    AutomaticFader__oneshot(arg0 + 0xCC, 0.0f, 4.0f, 0.0f, 0.25f);
}
