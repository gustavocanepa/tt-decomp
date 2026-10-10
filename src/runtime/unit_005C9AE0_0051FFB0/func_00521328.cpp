typedef unsigned int u32;

extern "C" void func_00521518();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B660;

extern int D_00793970;

extern "C" void *func_00521328(void) {
    if (D_00793970 == 0) {
        func_00521518();
        func_0050C6E8(&D_00793970, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B660);
    }
    return &D_00793970;
}
