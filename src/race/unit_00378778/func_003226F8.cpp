#include "types.h"

struct VEntry00379B08 {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj00379B08 {
    void *vtbl;
    char pad4[8];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

extern "C" f32 func_004A5DE0(f32 x);
extern "C" void func_00552C58(f32 *self, s32 out);
extern "C" void func_00552A68(f32 *self, s32 out);
extern "C" s32 func_003A91E8(s32 a0, f32 *a1, f32 *a2);

extern "C" s32 func_003226F8(struct Obj00379B08 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 buf[4];
    f32 vec[4];
    s32 result;
    f32 f20;
    f32 s;
    f32 *p;
    struct VEntry00379B08 *e;

    result = 0;
    if (arg2 != 0) {
        e = (struct VEntry00379B08 *)((char *)arg0->vtbl + 0x90);
        f20 = ((f32 (*)(void *))e->fn)((char *)arg0 + e->delta);
        s = f20 * func_004A5DE0((arg0->unkC * 0.5f * 3.14159265f) / 180.0f);
        f20 = f20 + s;
        buf[0] = f20;
        buf[1] = f20;
        buf[2] = f20;
        if (arg3 != 0) {
            func_00552C58(buf, arg3);
            func_00552A68(buf, arg3);
        }
        p = vec;
        *p = arg0->unk10;
        vec[1] = arg0->unk14;
        vec[2] = arg0->unk18;
        result = func_003A91E8(arg2, vec, buf);
    }
    return result;
}
