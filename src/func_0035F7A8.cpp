typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef signed char s8;

struct RPHD_arg0 {
    char pad0[0x1C];
    s8 *unk1C;
};

extern "C" s32 func_0035F540(s32, s32, f32);

extern "C" void RacePriusHybridDisplay__apply_patch(RPHD_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_s1;
    s32 base;

    if (arg0->unk1C != 0) {
        var_s1 = 0;
        base = (arg2 << 4) + arg3;
        if (arg4 > 0) {
            f32 denom = (f32)arg4;
            do {
                s8 *b = arg0->unk1C;
                s32 idx = base + var_s1;
                f32 fr = (f32)var_s1 / denom;
                s32 k = ((idx & 0xE7) | ((idx & 8) << 1) | ((idx & 0x10) >> 1)) << 2;
                s8 *dst;
                var_s1 += 1;
                dst = b + k;
                dst[0] = (s8)func_0035F540(arg1, 0, fr);
                dst[1] = (s8)func_0035F540(arg1, 1, fr);
                dst[2] = (s8)func_0035F540(arg1, 2, fr);
            } while (var_s1 < arg4);
        }
    }
}
