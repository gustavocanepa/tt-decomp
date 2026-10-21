#include "types.h"

extern "C" void func_00470B10(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern "C" void func_00470E60(s32 arg0);

extern "C" void func_00439978(void) {
    f32 zero = 0.0f;
    func_00470B10(zero, zero, zero, zero);
    func_00470E60(3);
}
