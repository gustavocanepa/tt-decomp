/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;

struct Cam { char pad0[0xC]; f32 f0C; char pad1[0x78 - 0x10]; f32 f78; };
struct S {
    long long q0;
    char pad0[0x44 - 8];
    f32 f44;
    f32 f48;
    f32 f4C;
    char pad1[0x80 - 0x50];
};

extern "C" void func_00322698(Cam *, f32);
extern "C" void func_003A67B8(S *, s32);
extern "C" f32 func_004A5DE0(f32);

extern "C" void func_003222B8(Cam *cam, S *src, f32 t) {
    f32 a = cam->f0C + (cam->f78 - cam->f0C) * t;
    S loc = *src;
    f32 ang = a * 0.5f * 0x1.1df468p-6f;
    f32 k = (1.0f / func_004A5DE0(ang)) * 0x1.66819ap-1f;
    f32 r = 1.0f / func_004A5DE0(ang);
    loc.f44 = src->f44 * k;
    loc.f48 = src->f48;
    loc.f4C = r;
    func_003A67B8(&loc, 1);
    func_00322698(cam, a);
}
