typedef unsigned int u32;

extern "C" void func_00521D28();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B668;

extern int D_00794E40;

extern "C" void *func_00555140(void) {
    if (D_00794E40 == 0) {
        func_00521D28();
        func_0050C6E8(&D_00794E40, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B668);
    }
    return &D_00794E40;
}
