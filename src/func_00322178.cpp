/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;

struct Cam { char pad0[0xC]; f32 fC; char pad1[0x1C - 0x10]; f32 f1C; f32 f20; f32 f24; };
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

extern "C" void func_00322178(Cam *cam, S *src) {
    S loc = *src;
    f32 *pc = &cam->fC;
    f32 v_f1C = cam->f1C;
    loc.f44 = src->f44 * v_f1C;
    loc.f48 = src->f48 * cam->f20;
    loc.f4C = cam->f24;
    func_003A67B8(&loc, 1);
    func_00322698(cam, *pc);
}
