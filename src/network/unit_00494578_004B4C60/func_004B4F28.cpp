/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
static inline void encode2(u8 *p, unsigned c) {
    u8 a = ((c >> 6) & 0x1f) | 0xc0;
    u8 b = (c & 0x3f) | 0x80;
    p[0] = a;
    p[1] = b;
}
static inline void encode3(u8 *p, unsigned c) {
    u8 a = ((c >> 12) & 0xf) | 0xe0;
    u8 b = ((c >> 6) & 0x3f) | 0x80;
    u8 d = (c & 0x3f) | 0x80;
    p[0] = a;
    p[1] = b;
    p[2] = d;
}
extern "C" u8 *func_004B4F28(u8 *p, unsigned c, int adv) {
    int n = 3;
    n -= c < 0x800;
    n -= c < 0x80;
    switch (n) {
    case 1: p[0] = c; break;
    case 2: encode2(p,c); break;
    case 3: encode3(p,c); break;
    }
    u8 *r = p + n;
    if (adv == 0) r = p;
    return r;
}
