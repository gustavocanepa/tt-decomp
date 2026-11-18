#include "types.h"

struct Inner {
    char pad0[0x20];
    f32 unk20;
};

struct Self {
    char pad0[0x184];
    struct Inner *unk184;
};

struct Arg2 {
    char pad0[0x44];
    f32 unk44;
};

extern "C" s32 func_003A91E8(s32 a, void *b, f32 *c);
extern "C" f32 func_004A5A68(f32 x);
extern "C" f32 func_004A5DE0(f32 x);

extern "C" s32 func_00329FE0(struct Self *arg0, s32 arg1, struct Arg2 *arg2, f32 fparg0) {
    f32 v[3];
    struct Inner *s2;
    f32 t;
    s32 r;

    s2 = arg0->unk184;
    t = arg2->unk44 * 0.70020754f * (1.0f / func_004A5DE0(fparg0 * 0.5f * 0.017453292f)) + 0.5f;
    v[0] = t;
    v[1] = t;
    v[2] = t;
    r = func_003A91E8(arg1, (char *)s2 + 4, v) ^ 1;
    if (fparg0 < (2.0f * func_004A5A68(1.0f / ((2.0f * s2->unk20) / 0.7f))) / 0.017453292f) {
        r = 0;
    }
    return r;
}
