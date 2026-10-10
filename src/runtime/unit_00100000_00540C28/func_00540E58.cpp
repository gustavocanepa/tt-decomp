typedef unsigned int u32;

extern "C" void func_00540B58();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007942A0;

extern int D_007942C0;

extern "C" void *func_00540E58(void) {
    if (D_007942C0 == 0) {
        func_00540B58();
        func_0050C6E8(&D_007942C0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007942A0);
    }
    return &D_007942C0;
}
