struct E { char p[8]; short v; char q[6]; };
struct S { char p[0x16]; unsigned short n; char q[4]; E *e; };
extern "C" int func_003F0EC8(S *s) {
    int r = 0;
    if (s->n != 0) {
        E *e = s->e;
        int n = s->n;
        do {
            int v = e->v;
            e++;
            n--;
            if (v >= 0) r++;
        } while (n != 0);
    }
    return r;
}
