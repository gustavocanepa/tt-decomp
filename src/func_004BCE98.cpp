/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned long u64;
static inline unsigned short read16(u8 *p) { return p[1] | (p[0] << 8); }
extern "C" int func_004BCE98(u8 *p, int i, u64 *a, u64 *b) {
    u8 h = p[i++];
    unsigned int type = h >> 4;
    if ((unsigned char)(type - 2) >= 2) return 1;
    u8 *q = p + i;
    i += 2;
    u8 *r = p + i;
    u64 v = (h >> 1) & 7;
    u64 top = v << 30;
    i += 2;
    {
        *a = top;
        v = (u64)read16(q) >> 1;
        u64 value = top | (v << 15);
        *a = value;
        v = (u64)read16(r) >> 1;
        value |= v;
        *a = value;
        if ((type ^ 3) != 0) return 0;
        {
            h = p[i++];
            u8 *q = p + i;
            i += 2;
            u8 *r = p + i;
            if ((h >> 4) != 1) return 1;
            {
                v = (h >> 1) & 7;
                u64 top = v << 30;
                        *b = top;
                v = (u64)read16(q) >> 1;
                u64 value = top | (v << 15);
                *b = value;
                v = (u64)read16(r) >> 1;
                *b = value | v;
            }
        }
    }
    return 0;
}
