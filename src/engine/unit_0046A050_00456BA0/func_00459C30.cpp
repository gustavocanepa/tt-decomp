/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct R {
    int pad0;
    int f4;
    int f8;
    int bits;
    u8 *f10;
    int f14;
    int f18;
    int f1C;
    int f20;
};
extern "C" void func_00459910(R *) throw();

extern "C" int func_00459C30(R *r, int n, int *out) {
    *out = 0;
    int res = 0;
    if (r->f20 != 0) return 0;
    while(n > 0) {
        if (r->bits < 0) {
            func_00459910(r);
            r->bits = 7;
            if (r->f18 == 0) {
                func_00459910(r);
                r->f18 = 1;
            }
            if (r->f14 != 0) {
                if (*r->f10 == 0xFF) {
                    if (r->f8 + 1 >= r->f4) {
                        r->f1C = 1;
                        r->f20 = 1;
                        return 0;
                    }
                    if(r->f10[1] != 0) {
                        *out = 1;
                        return r->f10[1] + 0xFF00;
                    }
                    r->f18 = 0;
                }
            } else {
                r->f1C = 1;
                r->f20 = 1;
                return 0;
            }
        }
        int c = *r->f10;
        int bit = r->bits;
        r->bits = bit - 1;
        res <<= 1;
        res |= (c >> bit) & 1;
        n--;
    }
    return res;
}
