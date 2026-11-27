/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

union Quat {
    u128 q;
    f32 f[4];
};

/* out = a * b (quaternions, w last) on VU0. */
extern "C" void func_00453FD0(u128 *out, Quat *a, Quat *b) {
    Quat t;
    int w = 3;

    t.f[w] = -a->f[0] * b->f[0] - a->f[1] * b->f[1] - a->f[2] * b->f[2] - a->f[w] * b->f[w];
    __asm__ volatile("qmtc2.i %0, $vf1" : : "r"(a->q));
    __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(b->q));
    __asm__ volatile("qmtc2.ni %0, $vf3" : : "r"(t.q));
    __asm__ volatile("vopmula.xyz ACC, $vf1, $vf2");
    __asm__ volatile("vopmsub.xyz $vf3, $vf2, $vf1");
    __asm__ volatile("vmulaw.xyzw ACC, $vf1, $vf2w");
    __asm__ volatile("vmaddw.xyzw $vf4, $vf2, $vf1w");
    __asm__ volatile("vadd.xyzw $vf3, $vf4, $vf3");
    __asm__ volatile("qmfc2.ni %0, $vf3" : "=r"(*out));
}
