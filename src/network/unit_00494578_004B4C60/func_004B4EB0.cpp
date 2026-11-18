/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004B4D88(const unsigned char **, int) throw();
extern "C" unsigned short *func_004B4EB0(unsigned short *dst, const unsigned char *src, int n) {
    unsigned short *d = dst;
    while (n-- > 0) {
        if ((*d++ = func_004B4D88(&src, 1)) == 0) return 0;
    }
    return dst;
}
