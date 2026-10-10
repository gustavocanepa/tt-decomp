typedef unsigned int u32;

extern "C" void func_00511F38();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B628;

extern int D_00793FD0;

extern "C" void *func_00536DE0(void) {
    if (D_00793FD0 == 0) {
        func_00511F38();
        func_0050C6E8(&D_00793FD0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B628);
    }
    return &D_00793FD0;
}
