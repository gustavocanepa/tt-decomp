/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned int u128 __attribute__((mode(TI)));

extern "C" int func_004692D8(u64 x, int y, int z) {
    union {
        u128 q;
        int w[4];
    } v;
    u128 in;
    u32 clip;
    int w;

    u64 xy = (u64)y << 32 | x;
    __asm__("pcpyld %0, %1, %2" : "=r"(in) : "0"(z), "r"(xy));
    __asm__ volatile("qmtc2.i %0, $vf1" : : "r"(in));
    __asm__ volatile("vmulax.xyzw ACC, $vf24, $vf1x");
    __asm__ volatile("vmadday.xyzw ACC, $vf25, $vf1y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf26, $vf1z");
    __asm__ volatile("vmaddw.xyzw $vf1, $vf27, $vf0w");
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
