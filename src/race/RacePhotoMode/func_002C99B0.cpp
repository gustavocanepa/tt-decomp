#include "types.h"

extern "C" s32 func_002C9998(void *arg0);
extern "C" void func_0030A5D0(void *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern "C" void func_002E51D0(void *arg0);

extern "C" void func_002C99B0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 temp_s0;

    temp_s0 = func_002C9998(arg0);
    func_0030A5D0((void *)temp_s0, -1, fparg0, -fparg1, 0.0f, fparg2);
    func_002E51D0((void *)temp_s0);
    func_002E51D0((void *)temp_s0);
}
