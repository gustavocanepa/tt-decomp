#include "types.h"

struct H {
    void *p;
    char pad[12];
};

struct Str {
    char *p;
    char pad[0xC];
};

extern "C" void func_0015A690(void *, int) throw();
extern "C" void func_0015A6E8(void *, void *) throw();
extern "C" s32 func_00166CB8(void *, s32, const char *);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" int func_0029E9F0(void *);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002ADBF0(void *, int);
extern "C" void func_002ADC48(void *, void *);
extern "C" Str *func_002AFE68(void *);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);

extern "C" void func_00164BD8(H *dst, void *a1, s32 n, char *args) {
    if (n >= 2) {
        H o0, h1, h2, h3;
        func_0015A6E8(&o0, a1);
        H *p1 = &h1;
        func_0029CF48(p1, args);
        H *p2 = &h2;
        func_002ADC48(p2, args + 4);
        void *o = o0.p;
        s32 v = func_0029E9F0(p1->p);
        Str *t = func_002AFE68(p2->p);
        const char *c;
        s32 len = *(s32 *)(t->p - 0x10);
        if (len == 0) {
            c = "";
        } else {
            t->p[len] = 0;
            c = t->p;
        }
        func_0029EA18(&h3, func_00166CB8(o, v, c));
        H *p3 = &h3;
        if (dst != p3) {
            void *s0 = p3->p;
            if (s0 != 0) {
                func_002C0FE8(s0);
            }
            if (dst->p != 0) {
                func_002C1050(dst->p);
            }
            dst->p = s0;
        }
        func_0029CEF0(p3, 2);
        func_002ADBF0(p2, 2);
        func_0029CEF0(p1, 2);
        func_0015A690(&o0, 2);
    }
}
