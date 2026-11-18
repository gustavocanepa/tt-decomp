/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

/* Loads VU0 register $vfN with the four 32-bit words (x, y, z, w). */
#define VU_SET_VF(n, x, y, z, w) do { u64 _x = (x), _y = (y), _z = (z), _w = (w); u128 _v; __asm__("pcpyld %0, %1, %2" : "=r"(_v) : "r"(_w << 32 | _z), "r"(_y << 32 | _x)); __asm__ volatile("qmtc2.i %0, $vf" #n : : "r"(_v)); } while (0)

struct State {
    char pad0[0x18];
    u32 qwc;
    char pad1C[0x30 - 0x1C];
    u32 tag[4];
    char pad40[0x48 - 0x40];
    u16 flags;
    char pad4A[0x1FC - 0x4A];
    u128 *top;
    char pad200[0x2E0 - 0x200];
    u128 a[3];
    char pad310[0x3A0 - 0x310];
    u128 e[2];
    char pad3C0[0xAA0 - 0x3C0];
    f32 dist;
    char padAA4[0xAC0 - 0xAA4];
    u128 light;
    char padAD0[0xB10 - 0xAD0];
    u32 scale;
    u32 alpha;
};

extern "C" void func_0046C798(State *s);
extern "C" void func_0046C8A0(State *s);
extern "C" void func_0046CAD8(State *s);

extern "C" void func_0046C630(State *s, f32 scale) {
    u128 *p;

    if ((u16)(s->flags & 1))
        func_0046C798(s);
    if (s->flags & 2)
        func_0046C8A0(s);
    if (s->flags & 4)
        func_0046CAD8(s);
    VU_SET_VF(10, s->scale, s->scale, s->scale, s->alpha);
    __asm__ volatile("lqc2 $vf5, %0" : : "m"(s->e[0]));
    __asm__ volatile("lqc2 $vf6, %0" : : "m"(s->e[1]));
    __asm__ volatile("lqc2 $vf1, %0" : : "m"(s->a[0]));
    __asm__ volatile("lqc2 $vf2, %0" : : "m"(s->a[1]));
    __asm__ volatile("lqc2 $vf3, %0" : : "m"(s->a[2]));
    __asm__ volatile("lqc2 $vf4, %0" : : "m"(s->light));
    __asm__ volatile("vmul.xyzw $vf5, $vf5, $vf10");
    __asm__ volatile("vmul.xyzw $vf6, $vf6, $vf10");
    if (scale != 0.0f) {
        __asm__ volatile("qmtc2.ni %0, $vf11" : : "r"(1.0f / scale));
        __asm__ volatile("vmulx.xyzw $vf4, $vf4, $vf11x");
    }
    p = s->top - 6;
    s->top = p;
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(p[0]));
    __asm__ volatile("sqc2 $vf2, %0" : "=m"(p[1]));
    __asm__ volatile("sqc2 $vf3, %0" : "=m"(p[2]));
    __asm__ volatile("sqc2 $vf4, %0" : "=m"(p[3]));
    __asm__ volatile("sqc2 $vf5, %0" : "=m"(p[4]));
    __asm__ volatile("sqc2 $vf6, %0" : "=m"(p[5]));
    if (s->dist < 6.0f)
        s->qwc = 0x195;
    else if (s->dist < 12.0f)
        s->qwc = 0x195;
    else
        s->qwc = 0x1D4;
    u32 addr = (u32)p & 0x0FFFFFFF;
    u32 tag = 0x30000006;
    u32 command = 0x6C06C0C9;
    s->tag[0] = tag;
    s->tag[3] = command;
    s->tag[1] = addr;
    s->tag[2] = 0;
}
