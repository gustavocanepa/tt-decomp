/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short adj; short pad; void (*fn)(void *, int); };
struct VT { char pad[8]; VE e8; };
struct Sub { VT *vt; };
struct Obj { char pad[0xC]; int flag[8]; Sub *sub; };
extern "C" int func_003F4538(int, float, float, float, float) throw() __attribute__((const));
extern "C" void func_0046F0F8(int);
extern "C" void func_00473A08(int, int, void *);
extern "C" void func_003F4618(Obj *o, int sel, float a, float b, float c, float d) {
    unsigned idx = sel & 0xFF;
    if (idx < 8) {
        Sub *s = o->sub;
        if (s) {
            VE *e = &s->vt->e8;
            e->fn((char *)s + e->adj, idx);
        } else {
            float v[4];
            v[0] = a; v[1] = b; v[2] = c; v[3] = d;
            int h = func_003F4538(idx, a, b, c, d);
            int off = idx * 4;
            int *flags = (int *)((char *)o + 0xC);
            int *p = (int *)((char *)flags + off);
            if (*p == 0) {
                func_0046F0F8(h);
                *p = 1;
            }
            func_00473A08(h, 1, v);
        }
    }
}
