extern "C" void func_00414ED8(unsigned char *, unsigned, int);
extern "C" void func_00414F50(unsigned char *buf, unsigned pos, unsigned val, unsigned n) {
    if (n < 0x20) val &= (1 << n) - 1;
    goto test;
top:
    {
        unsigned p = pos;
        pos += 8;
        int b = val & 0xFF;
        val >>= 8;
        n -= 8;
        func_00414ED8(buf, p, b);
    }
test:
    if (n >= 8) goto top;
    int sh = pos & 7;
    if (n != 0) {
        unsigned idx = pos >> 3;
        if (sh == 0) {
            unsigned char *p = buf + idx;
            int m = ((1 << n) - 1) & 0xFF;
            *p = (*p & ~m) | (m & val);
            return;
        }
        unsigned char *p = buf + idx;
        int m = ((1 << n) - 1) & 0xFF;
        int r = 8 - sh;
        int lm = (m << sh) & 0xFF;
        int hm = (m >> r) & 0xFF;
        unsigned lv = val << sh;
        unsigned hv = val >> r;
        unsigned char *q = p + 1;
        *p = lv | (*p & ~lm);
        *q = hv | (*q & ~hm);
    }
}
