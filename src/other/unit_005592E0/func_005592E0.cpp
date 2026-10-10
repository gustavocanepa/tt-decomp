typedef unsigned int u32;

extern "C" void func_005587A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795210;

extern int D_00795190;

extern "C" void *func_005592E0(void) {
    if (D_00795190 == 0) {
        func_005587A0();
        func_0050C6E8(&D_00795190, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795210);
    }
    return &D_00795190;
}
