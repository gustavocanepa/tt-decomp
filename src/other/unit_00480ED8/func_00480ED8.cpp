extern "C" int D_0058E090;
extern "C" char D_00770700[];
extern "C" void func_004B6760(void *buf, int size);

extern "C" void func_00480ED8(void) {
    int *done = &D_0058E090;
    if (*done == 0) {
        func_004B6760(D_00770700, 0x3180);
        *done = 1;
    }
}
