typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

union Vec4 {
    u128 q;
    f32 f[4];
};

/* out.xyz = a x b on VU0. */
extern "C" void func_00453F60(Vec4 *out, Vec4 *a, Vec4 *b) {
    __asm__ volatile("qmtc2.i %0, $vf1" : : "r"(a->q));
    __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(b->q));
    __asm__ volatile("vopmula.xyz ACC, $vf1, $vf2");
    __asm__ volatile("vopmsub.xyz $vf1, $vf2, $vf1");
    __asm__ volatile("qmfc2.ni %0, $vf1" : "=r"(out->q));
}
