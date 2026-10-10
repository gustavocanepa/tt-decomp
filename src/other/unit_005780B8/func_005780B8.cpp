typedef unsigned int u32;

extern "C" void func_00577AB8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA50;

extern int D_007A6950;

extern "C" void *func_005780B8(void) {
    if (D_007A6950 == 0) {
        func_00577AB8();
        func_0050C6E8(&D_007A6950, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA50);
    }
    return &D_007A6950;
}
