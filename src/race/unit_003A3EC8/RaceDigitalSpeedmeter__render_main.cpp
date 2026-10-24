/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

struct G { s32 m0; s32 m4; };
struct S {
    char pad0[1];
    u8 m1;
    char pad2[2];
    s16 m4;
    s16 m6;
    char pad8[4];
    f32 mC;
    char pad10[8];
    char m18[0x10];
    f32 m28;
    s32 m2C;
    u16 m30;
    s16 m32;
    u16 m34;
    u16 m36;
};

extern G D_00585CC8;
extern char D_005F55D0[];
extern char D_005F55D8[];

extern "C" f32 func_0038F448(s32, f32, f32);
extern "C" s32 func_0038F5F8(s32, f32);
extern "C" void func_00415510(void *, void *);
extern "C" void func_00415578(void *);
extern "C" f32 func_00415820(void *);
extern "C" void func_00415A10(void *, f32, f32, f32);
extern "C" void func_00415B10(void *, s32);
extern "C" f32 func_00415C58(void *, const char *);
extern "C" void func_00415D18(void *, const char *, ...);

static inline bool less(s32 a, s32 b) { return a < b; }

extern "C" void RaceDigitalSpeedmeter__render_main(S *o) {
    G *g = &D_00585CC8;
    f32 zero = 0.0f;
    func_00415510(g, o->m18 - 0 );
    g->m4 = 2;
    if (o->m28 == zero) {
        f32 a = func_00415820(g);
        f32 b = func_00415C58(g, D_005F55D0) / a;
        o->m28 = func_0038F448(o->m1, (f32)o->m4, b) + b;
    }
    {
        s32 c = o->m30 + 1;
        o->m30 = c;
        if (c & 1) {
            s32 v = o->m32 < 0 ? -o->m32 : o->m32;
            u16 old = o->m34;
            o->m36 = old;
            o->m34 = v;
        }
    }
    {
        s16 s0 = (s16)o->m36 >? (s16)o->m34;
        func_00415B10(g, func_0038F5F8(o->m2C, o->mC));
        func_00415A10(g, o->m28, (f32)o->m6, zero);
        func_00415D18(g, D_005F55D8, s0);
    }
    g->m4 = 0;
    func_00415578(g);
}
