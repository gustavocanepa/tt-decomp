/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef unsigned int u32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Packet {
    u32 tag[4];
    u128 mat[4];
    u128 m2[4];
};

struct State {
    char pad0[0x20];
    f32 scale;
    char pad24[0x1F8 - 0x24];
    Packet *cur;
    char pad1FC[0xFA0 - 0x1FC];
    u128 m[4];
};

extern "C" void func_0046BFE8(State *s, u32 reg, f32 scale) {
    Packet *p = s->cur;
    s->scale = scale;
    p->tag[0] = 0x10000008;
    p->tag[1] = 0;
    p->tag[2] = 0;
    p->tag[3] = reg | 0x6C08C000;
    __asm__ volatile("vnop");
    if (scale != 0.0f) {
        __asm__ volatile("qmtc2.ni %0, $vf4" : : "r"(scale));
        __asm__ volatile("vmulx.xyzw $vf1, $vf24, $vf4x");
        __asm__ volatile("vmulx.xyzw $vf2, $vf25, $vf4x");
        __asm__ volatile("vmulx.xyzw $vf3, $vf26, $vf4x");
        __asm__ volatile("sqc2 $vf1, %0" : "=m"(p->mat[0]));
        __asm__ volatile("sqc2 $vf2, %0" : "=m"(p->mat[1]));
        __asm__ volatile("sqc2 $vf3, %0" : "=m"(p->mat[2]));
        __asm__ volatile("sqc2 $vf27, %0" : "=m"(p->mat[3]));
    } else {
        __asm__ volatile("sqc2 $vf24, %0" : "=m"(p->mat[0]));
        __asm__ volatile("sqc2 $vf25, %0" : "=m"(p->mat[1]));
        __asm__ volatile("sqc2 $vf26, %0" : "=m"(p->mat[2]));
        __asm__ volatile("sqc2 $vf27, %0" : "=m"(p->mat[3]));
    }
    p->m2[0] = s->m[0];
    p->m2[1] = s->m[1];
    p->m2[2] = s->m[2];
    p->m2[3] = s->m[3];
    s->cur = p + 1;
}
