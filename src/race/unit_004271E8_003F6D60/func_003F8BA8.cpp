#include "types.h"

extern "C" s32 func_003F8A40(s32 a0, s32 a1, const char *a2, u8 a3, s32 t0, s32 t1);

struct func_003F8BA8_arg0 {
    char pad0[0xC04];
    s32 unkC04;
};

extern "C" s32 func_003F8BA8(s32 arg0, s32 arg1, u8 arg2) {
    return func_003F8A40(arg0, arg1, "%s%04d", arg2, 1, ((struct func_003F8BA8_arg0 *)arg0)->unkC04);
}
