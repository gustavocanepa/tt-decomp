typedef int s32;

extern s32 D_00584054;
extern char D_00584038[];
extern "C" void *func_0042FA10(char *);
extern "C" void func_004A45D0(void *);

extern "C" void func_0034A600(void) {
    if (D_00584054 != 0) {
        func_004A45D0(func_0042FA10(D_00584038));
    }
    D_00584054 = 0;
}
