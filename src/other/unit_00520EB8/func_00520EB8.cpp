typedef unsigned int u32;

extern "C" void func_00520DE0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007938F0;

extern int D_007938B0;

extern "C" void *func_00520EB8(void) {
    if (D_007938B0 == 0) {
        func_00520DE0();
        func_0050C6E8(&D_007938B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007938F0);
    }
    return &D_007938B0;
}
