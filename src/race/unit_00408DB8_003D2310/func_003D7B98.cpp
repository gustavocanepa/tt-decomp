/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Base { char p[0x23968]; int count; };
struct Self { Base *base; char p4[0x4C - 4]; u8 t[6][6]; };
extern "C" int func_0030E370(Base *, int, int, float *);

extern "C" u8 func_003D7B98(Self *self, int a, int *out) {
    float f;
    int best;
    u8 ret;
    int j;
    best = -1;
    int n = self->base->count;
    ret = 0;
    j = 0;
    if (n > 0) {
        do {
            if (j != a) {
                u8 x = self->t[a][j];
                u8 y = self->t[j][a];
                if (x >= 2 || y >= 2) {
                    int r = func_0030E370(self->base, a, j, &f);
                    int sc = 0;
                    if (r == 0) {
                        if (x == 3) sc = 5;
                        else if (y == 3) sc = 5;
                        else if (x == 2) sc = 4;
                        else if (y == 2) sc = 3;
                    } else {
                        sc = r < 0 ? 2 : 1;
                    }
                    if (ret < sc) {
                        best = j;
                        ret = sc;
                    }
                }
            }
            j++;
        } while (j < n);
    }
    *out = best;
    return ret;
}
