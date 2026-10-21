/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Scratch {
    u8 dirty;
    u8 current;
    char pad2[0x48 - 2];
    u16 flags;
    char pad4A[0xED0 - 0x4A];
    u128 matrix[4];
};

struct Light {
    char pad0[8];
    u8 enabled;
    char pad9[0x10 - 9];
    u128 v10;
    u128 v20;
    u128 v30;
    u128 v40;
    u128 v50;
    u128 v60;
    u128 v70;
    u128 v80;
    u128 v90;
};

/* vf2.xyzw /= |vf2.xyz| */
#define normalize_vf2() do {      __asm__ volatile("vmul.xyzw $vf1, $vf2, $vf2");     __asm__ volatile("vaddy.x $vf1, $vf1, $vf1y");     __asm__ volatile("vaddz.x $vf1, $vf1, $vf1z");     __asm__ volatile("vrsqrt Q, $vf0w, $vf1x");     __asm__ volatile("vwaitq");     __asm__ volatile("vmulq.xyzw $vf2, $vf2, Q"); } while (0)

#define TRANSFORM(s, v, direction, out) do {         __asm__ volatile("vnop");         __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(v));         if (!(direction) || ((f32 *)&v)[3] == 0.0f) {             normalize_vf2();         }         if (s->current == 0) {             __asm__ volatile("vmove.xyzw $vf20, $vf28");             __asm__ volatile("vmove.xyzw $vf21, $vf29");             __asm__ volatile("vmove.xyzw $vf22, $vf30");             __asm__ volatile("vmove.xyzw $vf23, $vf31");         } else {             __asm__ volatile("lqc2 $vf20, %0" : : "m"(s->matrix[0]));             __asm__ volatile("lqc2 $vf21, %0" : : "m"(s->matrix[1]));             __asm__ volatile("lqc2 $vf22, %0" : : "m"(s->matrix[2]));             __asm__ volatile("lqc2 $vf23, %0" : : "m"(s->matrix[3]));         }         __asm__ volatile("vmulax.xyzw ACC, $vf20, $vf2x");         __asm__ volatile("vmadday.xyzw ACC, $vf21, $vf2y");         __asm__ volatile("vmaddaz.xyzw ACC, $vf22, $vf2z");         __asm__ volatile("vmaddw.xyzw $vf2, $vf23, $vf2w");         __asm__ volatile("sqc2 $vf2, %0" : "=m"(out)); } while (0)

extern "C" void func_00479B08(Scratch *s, Light *l, u32 which, u128 v) {
    switch (which) {
    case 0:
        l->v10 = v;
        break;
    case 1:
        l->v20 = v;
        break;
    case 4:
        l->v40 = v;
        break;
    case 13:
        TRANSFORM(s, v, 1, l->v60);
        break;
    case 5:
        TRANSFORM(s, v, 0, l->v90);
        break;
    }
    if (l->enabled)
        s->flags |= 1;
}
