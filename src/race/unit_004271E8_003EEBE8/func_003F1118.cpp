struct E { char p0[4]; float f4; char p8[0x14]; int f1C; };
struct A { short p0, p2, f4, f6, f8; char pA[6]; };
struct G { char p0[8]; char *f8; char pC[4]; };
struct T { char p0[0x10]; G *f10; char p14[8]; A *f1C; };
extern "C" int func_003F1A08(void *p);
extern "C" E *func_003F1A10(void *p, int i);

static inline G *entry(G *base, int index) {
    base += index;
    return base;
}

extern "C" int func_003F1118(T *t, int idx, int lim, float *out) {
    if (idx < 0) return 0;
    A *a = (A *)(idx * 16 + (int)t->f1C);
    if (a->f6 >= 0) {
        *out = 0;
        return 1;
    }
    int k = a->f8;
    if (k >= 0) {
        int m = a->f4;
        char *g = entry(t->f10, m)->f8 + (k << 5);
        int i = 0;
        while (i < func_003F1A08(g)) {
            E *e = func_003F1A10(g, i);
            if (e->f1C >= lim) {
                *out = e->f4;
                return 1;
            }
            i++;
        }
    }
    return 0;
}
