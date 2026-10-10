typedef unsigned int u32;

extern "C" void func_00520EB8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007938B0;

extern int D_00793880;

extern "C" void *func_00520390(void) {
    if (D_00793880 == 0) {
        func_00520EB8();
        func_0050C6E8(&D_00793880, ((char *)"Q212GranTurismo413UpdateManager"), &D_007938B0);
    }
    return &D_00793880;
}
