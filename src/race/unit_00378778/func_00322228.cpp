/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;

struct Cam { char pad1[0x1C]; f32 f1C; f32 f20; f32 f24; };
struct S {
    long long q0;
    char pad0[0x44 - 8];
    f32 f44;
    f32 f48;
    f32 f4C;
    char pad1[0x80 - 0x50];
};

extern "C" void func_003A6938(S *, void *, s32);

extern "C" void func_00322228(Cam *cam, void *out, S *src) {
    S loc = *src;
    loc.f4C = cam->f24;
    f32 near_scale = cam->f1C;
    f32 far_scale = cam->f20;
    loc.f44 = src->f44 * near_scale;
    loc.f48 = src->f48 * far_scale;
    func_003A6938(&loc, out, 1);
}
