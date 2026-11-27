/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
typedef float f32;

struct Arg1 {
    char pad[0x18];
    u16 f18;
};
struct Self {
    char pad[0x2C];
    unsigned char f2C;
    char pad2D[0x40 - 0x2D];
    s32 f40;
};

struct Self;
extern "C" void func_00420600(Self *, u16) throw();
extern "C" void func_0046AC38(s32);
extern "C" void func_0046AE40(s32);
extern "C" void func_0046AEA0();
extern "C" void func_0046CE60(s32, f32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_004701C0(s32);
extern "C" void func_00470298(s32);
extern "C" void func_004702D8(s32, float);
extern "C" void func_00470328(s32, float);
extern "C" void func_00470388(s32, s32);
extern "C" void func_00470450(int);
extern "C" void func_00470478(int);
extern "C" void func_00470AF0(float);
extern "C" void func_00473EF0(f32, f32, f32, f32);
extern "C" void func_00473F10(float, float, float, float);
extern "C" void func_00478C98(s32);

extern s32 D_00585D20;
extern s32 D_00585D24;
extern f32 D_00585D28;
extern f32 D_00585D2C;
extern s32 D_00585D44;

extern "C" void ModelSet2__begin(Self *self, Arg1 *arg1) {
    if (arg1 != 0) {
        if (self->f2C != 0) {
            func_00420600(self, arg1->f18);
        }
    }
    if (D_00585D20 != 0) {
        func_0046F0F8(5);
    } else {
        func_00478C98(5);
    }
    func_0046F0F8(4);
    func_00478C98(3);
    func_0046F0F8(0xF);
    func_0046F0F8(0x11);
    func_004702D8(0x44, 0.0f);
    func_00470AF0(0.0f);
    if (D_00585D24 != 0) {
        func_00470478(1);
    }
    if (D_00585D44 != 0) {
        func_00470450(-1);
    }
    func_004701C0(3);
    func_00470388(6, 0x20);
    func_00470328(5, 0.5f);
    func_00470298(0);
    func_0046CE60(3, D_00585D28);
    func_0046CE60(2, D_00585D2C);
    func_00473EF0(1.0f, 1.0f, 1.0f, 1.0f);
    func_00473F10(0.0f, 0.0f, 0.0f, 0.0f);
    func_0046AE40(self->f40);
    func_0046AC38((s32)func_0046AEA0);
}
