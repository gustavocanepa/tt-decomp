/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" unsigned int D_00586F08;
extern "C" float func_00464018(void) {
    float f;
    unsigned int bits;
    D_00586F08 = D_00586F08 * 0x5D588B65 + 1;
    bits = (D_00586F08 & 0x7FFFFF) | 0x3F800000;
    __asm__("mtc1 %1, %0" : "=f"(f) : "r"(bits));
    return f;
}
