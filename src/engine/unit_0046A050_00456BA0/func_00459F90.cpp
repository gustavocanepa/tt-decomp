/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned int u32;
struct S { char p0[0xC]; int bits; u8 *ptr; char p14[4]; int flag; };
extern "C" int func_00459F90(S *s, int *out) {
    int n = s->bits;
    int k = 16;
    u8 *p = s->ptr;
    int flag = s->flag;
    if (n < 0) {
        p++;
        n = 7;
        if (flag == 0) { flag = 1; p++; *out = 1; }
        if (*p == 0xFF) {
            *out = 1;
            if (p[1] != 0) return p[1] + 0xFF00;
            flag = 0;
        }
    }
    k = k - n - 1;
    n = *p;
    if (k > 0) {
        do {
            p++;
            if (flag == 0) { flag = 1; p++; *out = 1; }
            if (*p == 0xFF) {
                *out = 1;
                if (p[1] == 0) flag = 0;
            }
            k -= 8;
            n = (n << 8) | *p;
        } while (k > 0);
    }
    return ((unsigned)n >> -k) & 0xFFFF;
}
