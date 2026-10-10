typedef unsigned int u32;

extern "C" void func_0055E1D0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795520;

extern int D_00795540;

extern "C" void *func_0055E3A0(void) {
    if (D_00795540 == 0) {
        func_0055E1D0();
        func_0050C6E8(&D_00795540, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795520);
    }
    return &D_00795540;
}
