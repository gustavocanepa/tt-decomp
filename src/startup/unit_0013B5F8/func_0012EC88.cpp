/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEnt { s16 delta; s16 pad; s32 (*fn)(void *); };
struct VT { char pad[0x68]; VEnt e; };
struct VO { char pad[4]; VT *vt; };
struct Arg { VO *a; VO *b; };
extern "C" {
void func_00128418(void *, int) throw();
void func_00128470(void *) throw();
int func_001324D8(void *);
void func_0029CEF0(void *, int);
void func_0029EA18(void *, int);
void func_002C0FE8(void *);
void func_002C1050(void *);
s32 func_00406A88(s32, s32, s32);
s32 func_00412250(s32, s32, s32);

static inline s32 vcall(VO *o) {
    VEnt *e = &o->vt->e;
    return e->fn((char *)o + e->delta);
}

void func_0012EC88(void **arg0, s32 arg1, s32 arg2, Arg *arg3) {
    if (arg2 >= 2) {
        s32 obj;
        void *h[4];
        func_00128470(&obj);
        s32 s2 = vcall(arg3->a);
        s32 s0 = vcall(arg3->b);
        s32 r = func_00406A88(func_001324D8((void *)obj), s2, s0);
        if (r != 0 || (s0 > 0 && func_00412250(obj + 0x18, s2, s0 - 1) == 0)) {
            void **ph = h;
            func_0029EA18(ph, 1);
            if (arg0 != ph) {
                void *p = ph[0];
                if (p != 0) func_002C0FE8(p);
                if (*arg0 != 0) {
                    func_002C1050(*arg0);
                    *arg0 = p;
                } else {
                    *arg0 = p;
                }
            }
            func_0029CEF0(ph, 2);
        } else {
            void **ph = h;
            func_0029EA18(ph, 0);
            if (arg0 != ph) {
                void *p = ph[0];
                if (p != 0) func_002C0FE8(p);
                if (*arg0 != 0) {
                    func_002C1050(*arg0);
                    *arg0 = p;
                } else {
                    *arg0 = p;
                }
            }
            func_0029CEF0(ph, 2);
        }
        func_00128418(&obj, 2);
    }
}
}
