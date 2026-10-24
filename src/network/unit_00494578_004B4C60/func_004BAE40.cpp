/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00776B84[];
extern "C" int func_004FB6E8(int);
extern "C" void func_004BAE40(int unused0, int unused1, int arg2) {
    *(volatile int *)D_00776B84 = -1;
    func_004FB6E8(arg2);
    __asm__ volatile("sync");
    __asm__ volatile("ei");
}
