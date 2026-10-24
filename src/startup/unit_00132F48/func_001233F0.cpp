/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned long long u64;
struct T { s16 lo; s16 hi; };
struct VEnt { s16 delta; s16 pad; s32 (*fn)(void *); };
struct VT { char pad[0x68]; VEnt e; };
struct VO { char pad[4]; VT *vt; };
extern "C" {
void func_002931C8(void *, int);
void *func_002944D0(void *, void *, void *);
void func_00295180(void *);
void func_0029CEF0(void *, int);
void func_0029EA18(void *, s32);
void func_002A7578(void *, void *);
void func_002A75A8(void *, s32);
void func_002C0FE8(void *);
void func_002C1050(void *);
T func_004AF620(s32);

void func_001233F0(void **arg0, s32 arg1, VO **arg2) {
    if (arg1 > 0) {
        VO *o = *arg2;
        VEnt *e = &o->vt->e;
        T t = func_004AF620(e->fn((char *)o + e->delta));
        void *h[4];
        void *tmp[4];
        void *a[4];
        void *b[4];
        void *c[4];
        void **ph = h;
        func_00295180(ph);
        void *s1 = ph[0];
        void **ptmp = tmp;
        func_0029EA18(a, t.lo);
        func_002944D0(ptmp, s1, a);
        func_002A75A8(ptmp, 2);
        func_0029CEF0(a, 2);
        void *s1b = ph[0];
        func_0029EA18(b, (u8)t.hi);
        func_002944D0(ptmp, s1b, b);
        func_002A75A8(ptmp, 2);
        func_0029CEF0(b, 2);
        void *s1c = ph[0];
        func_0029EA18(c, (u8)(t.hi >> 8));
        func_002944D0(ptmp, s1c, c);
        func_002A75A8(ptmp, 2);
        func_0029CEF0(c, 2);
        if (arg0 != ph) {
            void *p = ph[0];
            if (p != 0) func_002C0FE8(p);
            if (*arg0 != 0) func_002C1050(*arg0);
            *arg0 = p;
        }
        func_002931C8(ph, 2);
    } else {
        void *hh[4];
        s32 z;
        z = 0;
        func_002A7578(hh, &z);
        if (arg0 != hh) {
            void *p = hh[0];
            if (p != 0) func_002C0FE8(p);
            if (*arg0 != 0) func_002C1050(*arg0);
            *arg0 = p;
        }
        func_002A75A8(hh, 2);
    }
}
}
