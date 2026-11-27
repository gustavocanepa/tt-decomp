/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
extern "C" void func_00414ED8(u8 *buf, unsigned bit, int val) {
    unsigned sh = bit & 7;
    bit >>= 3;
    u8 v = val;
    if (sh == 0) {
        u8 *p = buf + bit;
        *p = v;
        return;
    }
    u8 *p = buf + bit;
    u8 *q = p + 1;
    int lo = v << sh;
    int r = 8 - sh;
    int m0 = (0xFF << sh) & 0xFF;
    unsigned m1 = (0xFFu >> r) & 0xFF;
    *p = lo | (*p & ~m0);
    *q = (v >> r) | (*q & ~m1);
}
