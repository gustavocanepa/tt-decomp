/* compiler: ee-gcc2.96-no-strict-aliasing */
extern volatile int D_0059C0D8;
extern "C" void func_004C9978(void);
extern "C" void func_004C4728(void) {
    volatile int *flag = &D_0059C0D8;
    if (*flag != 0) {
        *flag = 0;
        func_004C9978();
    }
}
