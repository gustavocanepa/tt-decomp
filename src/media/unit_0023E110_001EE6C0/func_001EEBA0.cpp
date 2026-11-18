#include "types.h"
struct S { char pad[0x10]; void *f10; };
extern "C" s32 func_004A8268(s32, const char *);
extern "C" s32 dpdiv(s64, s32);
extern "C" f32 dptofp(s32);
extern "C" s32 func_004B4C18(f32);
extern "C" void func_002662B8(void *, s32, f32);
extern "C" void func_001EEBA0(S *arg0, s32 arg1, f32 fparg0) {
    if (func_004A8268(arg1, "keep") != 0) {
        s64 k = 0xFFC0;
        func_002662B8(arg0->f10, arg1, dptofp(dpdiv(k << 46, func_004B4C18(fparg0 * 60.0f))));
    }
}
