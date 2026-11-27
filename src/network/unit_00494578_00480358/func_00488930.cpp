/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short adj; short pad; int (*fn)(char *, int); };
struct VT { char pad[8]; VE e8; char pad2[0x18 - 0x10]; VE e18; };
struct O { char pad[0x78]; VT *vt; };
struct R { int f0, f4, f8, fC; };
extern "C" int func_00488930(O *o, R *r, unsigned n) {
    int res = 0;
    unsigned i = 0;
    for (;;) {
        if (i < n) {
            i++;
            VE *e = &o->vt->e8;
            if (e->fn((char *)o + e->adj, r->f0) != 0) {
                r->f8 = 0;
                r->fC = 0;
                break;
            }
        } else {
            break;
        }
        VE *e2 = &o->vt->e18;
        res = e2->fn((char *)o + e2->adj, r->f0);
        if (res < 0) break;
        int v = r->f0;
        r->f0 = res;
        r->f4 = v;
    }
    return res;
}
