/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct R {
    s32 u0, u4, u8, uC;
    s32 x, y, w, h;
    char pad[0x20];
};
struct Obj {
    char pad0[4];
    s32 u4;
    char pad8[0x28 - 8];
    s32 u28;
};

extern "C" void func_00104868(void *, s32);
extern "C" s32 func_001048C8(void *, s32, s32, s32);
extern "C" void func_00104C88(void *);
extern "C" void func_00104D10(void *);
extern "C" void func_00104FE0(void *, s32, s32);
extern "C" void func_00470478(s32);
extern "C" void func_00472268(s32, s32);
extern "C" void func_00474318( f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_00477DC0(s32);
extern "C" void func_00478C98(s32);

extern "C" void func_002C2F90(Obj *arg0, R *arg1, s32 arg2) {
    R a;
    R b;
    f32 c, d, z, e, e2;
    s32 h1, h2;

    func_001048C8(&a, 0, 0x80, 0x80);
    func_001048C8(&b, 2, 0x40, 0x40);
    func_00477DC0(0x80FFFFFF);
    func_00472268(3, 1);
    func_00472268(2, 1);
    func_00478C98(5);
    func_00478C98(4);
    func_00470478(0);
    func_00478C98(6);
    func_00104D10(arg1);
    func_00104C88(&a);
    c = (f32)(arg1->x + arg1->w) * 0.5f;
    e = (f32)(arg1->y + arg1->h);
    d = c;
    if (arg2 != 0) {
        d = c * 0.75f;
    }
    z = 0.0f;
    func_00474318( z, z, 128.0f, 128.0f, c - d, z, c + d, e);
    func_00104D10(&a);
    func_00104C88(&b);
    func_00474318( z, z, 64.0f, 64.0f, z, z, (f32)(a.x + a.w), (f32)(a.y + a.h));
    func_00104FE0(&b, arg0->u4, 2);
    arg0->u28 = 1;
    func_00104868(&b, 2);
    func_00104868(&a, 2);
}
