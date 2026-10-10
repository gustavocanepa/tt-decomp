extern signed char D_0058C50C;

extern "C" unsigned char func_00477F60(void);

extern "C" void func_00477FA8(unsigned char *buf, int n) {
    if (D_0058C50C)
        return;
    for (int i = 0; i < n; i++)
        *buf++ ^= func_00477F60();
    D_0058C50C = 1;
}
