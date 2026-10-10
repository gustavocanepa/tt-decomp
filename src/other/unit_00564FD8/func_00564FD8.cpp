typedef unsigned int u32;

extern "C" void func_00561EF8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795930;

extern int D_00795A70;

extern "C" void *func_00564FD8(void) {
    if (D_00795A70 == 0) {
        func_00561EF8();
        func_0050C6E8(&D_00795A70, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795930);
    }
    return &D_00795A70;
}
