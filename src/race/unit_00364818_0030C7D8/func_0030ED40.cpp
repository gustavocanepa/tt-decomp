/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self {char pad0[0x2C]; float x[8]; float y[8]; char sub[1];};
struct Data {char pad0[2]; unsigned char nl, nr; char pad1[8]; unsigned char l0[4]; unsigned char l1[4]; unsigned char r0[4]; unsigned char r1[4];};
extern "C" int func_002FD8A0(char *, int, float *, float *, int, int);
extern "C" int func_0030ED40(Self *self, Data *d, int flag, float sa, float sb, float sc){
    char *sub = self->sub;
    float *x = self->x;
    float *y = self->y;
    int i;
    unsigned char *r1 = d->r1, *l0 = d->l0, *r0 = d->r0, *l1 = d->l1;
    int n = d->nl, m = d->nr;
    for (i = 0; i < n; i++) {
        x[i] = -(float)l0[n - 1 - i] * sa;
        y[i] = (float)l1[n - 1 - i] * sb;
    }
    for (i = 0; i < m; i++) {
        x[n + i] = (float)r0[i] * sa;
        y[n + i] = (float)r1[i] * sc;
    }
    return func_002FD8A0(sub, n + m, x, y, flag ? 2 : 0, 0);
}
