extern int D_00584054;
extern char D_00584038[];

extern "C" void *func_004AE6D8(int size);
extern "C" int func_0042FA28(void *heap, void *mem, int total, int size);

extern "C" void func_0034A590(int size) {
    int *initialized = &D_00584054;
    if (*initialized == 0) {
        int total = size + 0x100;
        func_0042FA28(D_00584038, func_004AE6D8(total), total, size);
        *initialized = 1;
    }
}
