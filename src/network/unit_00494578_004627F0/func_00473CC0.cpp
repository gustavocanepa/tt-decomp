/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004751E0(void);

extern "C" float func_00473CC0(void) {
    float r;
    func_004751E0();
    __asm__ volatile("qmfc2.i %0, $vf1" : "=r"(r));
    return r;
}
