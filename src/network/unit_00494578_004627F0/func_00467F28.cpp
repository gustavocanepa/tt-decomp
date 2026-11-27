/* compiler: ee-gcc2.96-as2004 */
typedef float f32;
typedef unsigned char u8;
typedef unsigned long u64;
struct XY {
    u64 v;
} __attribute__((packed));
typedef unsigned int u128 __attribute__((mode(TI)));

struct Scratch {
    u8 dirty;
    char pad1[0xFA0 - 1];
    u128 m[4];
};

struct V3 {
    f32 x, y, z;
};

extern "C" void func_0046BF20(Scratch *s);

extern "C" void func_00467F28(Scratch *s, V3 *v) {
    if (s->dirty)
        func_0046BF20(s);
    u64 b = ((XY *)&v[1])->v;
    u64 c = ((XY *)&v[2])->v;
    u64 a = ((XY *)&v[0])->v;
    __asm__ volatile("vnop");
    __asm__ volatile("lqc2 $vf20, %0" : : "m"(s->m[0]));
    __asm__ volatile("lqc2 $vf21, %0" : : "m"(s->m[1]));
    __asm__ volatile("lqc2 $vf22, %0" : : "m"(s->m[2]));
    __asm__ volatile("lqc2 $vf23, %0" : : "m"(s->m[3]));
    __asm__ volatile("qmtc2.i %0, $vf1" : : "r"(a));
    __asm__ volatile("qmtc2.i %0, $vf2" : : "r"(b));
    __asm__ volatile("qmtc2.i %0, $vf3" : : "r"(c));
    __asm__ volatile("vmulax.xyzw ACC, $vf24, $vf1x");
    __asm__ volatile("vmaddy.xyzw $vf16, $vf25, $vf1y");
    __asm__ volatile("vmulax.xyzw ACC, $vf24, $vf2x");
    __asm__ volatile("vmaddy.xyzw $vf17, $vf25, $vf2y");
    __asm__ volatile("vmulx.xyzw $vf18, $vf0, $vf0x");
    __asm__ volatile("vmulax.xyzw ACC, $vf24, $vf3x");
    __asm__ volatile("vmadday.xyzw ACC, $vf25, $vf3y");
    __asm__ volatile("vmaddw.xyzw $vf19, $vf27, $vf0w");
}
