typedef unsigned int u32;

extern "C" void func_00560C38();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007957E0;

extern int D_00795800;

extern "C" void *func_00560C98(void) {
    if (D_00795800 == 0) {
        func_00560C38();
        func_0050C6E8(&D_00795800, ((char *)"Q212GranTurismo413UpdateManager"), &D_007957E0);
    }
    return &D_00795800;
}
