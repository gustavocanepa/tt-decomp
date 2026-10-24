typedef int s32; typedef float f32;

extern "C" s32 func_00319860(void *, f32);
extern "C" void func_003AA3E8(void *, void *, void *, s32);

extern "C" void func_00319A68(void **self, f32 *width, f32 *ang, void *p, s32 idx) {
    f32 sp[3];
    func_003AA3E8(sp, *self, p, idx);
    f32 w = sp[2] - sp[1];
    if (w < 0.001f) w = 0.001f;
    f32 cur = *width;
    if (w < cur) {
        *width = w;
        cur = w;
    }
    f32 half = cur * 0.5f;
    f32 lo = sp[0];
    f32 a = *ang;
    if (a < lo) {
        s32 r = func_00319860(sp, a);
        lo = sp[0];
        if (r == 0) {
            f32 t = *ang + 360.0f;
            *ang = t;
            a = t;
        } else {
            a = *ang;
        }
    }
    if (lo < a) {
        if (func_00319860(sp, a) == 0) {
            f32 t = *ang - 360.0f;
            *ang = t;
            a = t;
        } else {
            a = *ang;
        }
    }
    if (a - half < sp[1]) {
        f32 t = sp[1] + half;
        *ang = t;
        a = t;
    }
    if (sp[2] < a + half) {
        *ang = sp[2] - half;
    }
}
