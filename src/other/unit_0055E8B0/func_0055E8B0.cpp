typedef unsigned int u32;

extern "C" void func_0055E3A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795540;

extern int D_00795580;

extern "C" void *func_0055E8B0(void) {
    if (D_00795580 == 0) {
        func_0055E3A0();
        func_0050C6E8(&D_00795580, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795540);
    }
    return &D_00795580;
}
