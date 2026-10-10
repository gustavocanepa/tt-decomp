typedef unsigned long long u64;

extern "C" void func_004751E0(void);

extern "C" void func_00473D10(float *x, float *y) {
    u64 q;
    float fx, fy;
    func_004751E0();
    __asm__ volatile(
        "qmfc2.i %2, $vf1\n"
        "mtc1 %2, %0\n"
        "dsrl32 %2, %2, 0\n"
        "mtc1 %2, %1\n"
        : "=f"(fx), "=f"(fy), "=r"(q));
    *x = fx;
    *y = fy;
}
