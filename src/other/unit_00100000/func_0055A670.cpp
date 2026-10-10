typedef unsigned int u32;

extern "C" void func_00556128();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794EF0;

extern int D_00795340;

extern "C" void *func_0055A670(void) {
    if (D_00795340 == 0) {
        func_00556128();
        func_0050C6E8(&D_00795340, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794EF0);
    }
    return &D_00795340;
}
