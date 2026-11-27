/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0049E940(const void *enc, const char *p, const char *end, const char *ascii) {
    int test = *ascii;
    short c = test;
    while (test) {
        if (p == end) return 0;
        if (p[1] != 0 || p[0] != (char)c) return 0;
        p += 2;
        ++ascii;
        unsigned char next = *(const unsigned char *)ascii;
        c = next;
        test = next;
    }
    return p == end;
}
