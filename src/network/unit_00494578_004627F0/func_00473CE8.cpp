/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;
extern "C" void func_004751E0(void);

extern "C" float func_00473CE8(void) {
    u64 v;
    float r;
    func_004751E0();
    __asm__ volatile("qmfc2.i %0, $vf1" : "=r"(v));
    __asm__ volatile("mtc1 %1, %0" : "=f"(r) : "r"(v >> 32));
    return r;
}
