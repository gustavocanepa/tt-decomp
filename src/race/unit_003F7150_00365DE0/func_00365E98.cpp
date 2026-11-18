/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int D_0058441C;
extern "C" int DisplayRText__load_rtext(void);
extern "C" void func_00365F60(int);
extern "C" void func_00365FE8(void);
extern "C" int func_00365E98(void) {
    int *p = &D_0058441C;
    if (*p == 0) {
        DisplayRText__load_rtext();
        func_00365F60(0x6A);
        func_00365FE8();
    }
    ++*p;
}
