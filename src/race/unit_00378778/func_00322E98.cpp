/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;
typedef unsigned char u8;

struct Cam { char pad0[0x24]; f32 f24; char pad2[0x292 - 0x28]; u8 m266; };
struct S {
    long long q0;
    char pad0[0x4C - 8];
    f32 f4C;
    char pad1[0x80 - 0x50];
};

extern "C" void func_003A6938(S *, void *, u8);

extern "C" void func_00322E98(Cam *cam, void *arg1, S *src) {
    S loc = *src;
    loc.f4C = cam->f24;
    func_003A6938(&loc, arg1, cam->m266);
}
