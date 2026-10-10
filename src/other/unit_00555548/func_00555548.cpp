typedef unsigned int u32;

extern "C" void func_00551078();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794B70;

extern int D_00794E80;

extern "C" void *func_00555548(void) {
    if (D_00794E80 == 0) {
        func_00551078();
        func_0050C6E8(&D_00794E80, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794B70);
    }
    return &D_00794E80;
}
