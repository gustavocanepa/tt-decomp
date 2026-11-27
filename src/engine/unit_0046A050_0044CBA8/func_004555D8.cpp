typedef unsigned int u128 __attribute__((mode(TI)));

/* out = a * b on VU0 (4x4 matrices, rows of b transformed by a). */
extern "C" void func_004555D8(u128 *out, u128 *a, u128 *b) {

    __asm__ volatile("qmtc2.i %0, $vf1" : : "r"(b[0]));
    __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(b[1]));
    __asm__ volatile("qmtc2.ni %0, $vf3" : : "r"(b[2]));
    __asm__ volatile("qmtc2.ni %0, $vf4" : : "r"(b[3]));
    __asm__ volatile("qmtc2.ni %0, $vf5" : : "r"(a[0]));
    __asm__ volatile("qmtc2.ni %0, $vf6" : : "r"(a[1]));
    __asm__ volatile("qmtc2.ni %0, $vf7" : : "r"(a[2]));
    __asm__ volatile("qmtc2.ni %0, $vf8" : : "r"(a[3]));
    __asm__ volatile("vmulax.xyzw ACC, $vf5, $vf1x");
    __asm__ volatile("vmadday.xyzw ACC, $vf6, $vf1y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf7, $vf1z");
    __asm__ volatile("vmaddw.xyzw $vf1, $vf8, $vf1w");
    __asm__ volatile("vmulax.xyzw ACC, $vf5, $vf2x");
    __asm__ volatile("vmadday.xyzw ACC, $vf6, $vf2y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf7, $vf2z");
    __asm__ volatile("vmaddw.xyzw $vf2, $vf8, $vf2w");
    __asm__ volatile("vmulax.xyzw ACC, $vf5, $vf3x");
    __asm__ volatile("vmadday.xyzw ACC, $vf6, $vf3y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf7, $vf3z");
    __asm__ volatile("vmaddw.xyzw $vf3, $vf8, $vf3w");
    __asm__ volatile("vmulax.xyzw ACC, $vf5, $vf4x");
    __asm__ volatile("vmadday.xyzw ACC, $vf6, $vf4y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf7, $vf4z");
    __asm__ volatile("vmaddw.xyzw $vf4, $vf8, $vf4w");
    __asm__ volatile("qmfc2.ni %0, $vf1" : "=r"(out[0]));
    __asm__ volatile("qmfc2.ni %0, $vf2" : "=r"(out[1]));
    __asm__ volatile("qmfc2.ni %0, $vf3" : "=r"(out[2]));
    __asm__ volatile("qmfc2.ni %0, $vf4" : "=r"(out[3]));
}
