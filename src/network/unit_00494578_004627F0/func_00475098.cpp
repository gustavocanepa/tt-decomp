/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec4 {
    u64 lo;
    u64 hi;
} __attribute__((packed));

extern "C" int func_00475098(Vec4 *p) {
    union {
        u128 q;
        int w[4];
    } v;
    u128 in;
    u32 clip;
    int w;

    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(in) : "0"(p->hi), "r"(p->lo));
    __asm__ volatile("qmtc2.ni %0, $vf1" : : "r"(in));
    __asm__ volatile("vclipw.xyzw $vf1, $vf1w");
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(v.q));
    __asm__ volatile("vnop");
    __asm__ volatile("vnop");
    __asm__ volatile("vnop");
    w = v.w[3];
    __asm__ volatile("vnop");
    __asm__ volatile("cfc2.i %0, $vi18" : "=r"(clip));
    if (w < 0)
        clip = ((clip >> 1) | 0x2A) ^ ((clip << 1) | 0x15);
    return clip & 0x3F;
}
