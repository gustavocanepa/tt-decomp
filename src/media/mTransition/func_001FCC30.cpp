/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct RefCounter;
struct E { short delta, index; void *(*fn)(void *); };
struct E2 { short delta, index; void *(*fn)(void *, void *); };
struct O { int pad; char *vt; };
extern "C" void func_001FCB58(void *, void *) throw();
extern "C" void func_001FCB00(void *, int) throw();
extern "C" void func_0029EA18(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_002C0FE8(RefCounter *);
extern "C" void func_002C1050(RefCounter *);
extern "C" void func_001FCC30(s32 *out, void *in, int n, O **other) {
    s32 b0[4];
    s32 b1[4];
    if (n == 1) {
        func_001FCB58(b0, in);
        O *o = *other;
        char *self = (char *)b0[0];
        E *e = (E *)(o->vt + 0x68);
        E2 *e2 = (E2 *)(((O *)self)->vt + 0x208);
        self = self + e2->delta;
        void *r = e->fn((char *)o + e->delta);
        r = e2->fn(self, r);
        s32 *p = b1;
        func_0029EA18(p, r);
        if (out != p) {
            s32 v = *p;
            if (v) func_002C0FE8((RefCounter *)v);
            s32 old = *out;
            if (old) func_002C1050((RefCounter *)old);
            *out = v;
        }
        func_0029CEF0(p, 2);
        func_001FCB00(b0, 2);
    }
}
