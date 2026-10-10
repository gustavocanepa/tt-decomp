extern unsigned short D_0060C4A8[];

extern "C" void func_0019B0D8(char *dst, const char *src) {
    char c;
    while ((c = *src++) != 0) {
        int w = D_0060C4A8[c];
        dst[1] = w;
        dst[0] = w >> 8;
        dst += 2;
    }
    *dst = 0;
}
