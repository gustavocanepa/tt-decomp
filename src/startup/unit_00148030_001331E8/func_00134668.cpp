#include "types.h"

struct Handle {
    void *p;
    char pad[0xC];
};

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_00128418(void *arg0, int arg1);
extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" void *func_001324D8(void *arg0);
extern "C" s32 func_004061F8(void *arg0);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, int arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);

static inline s32 vcall(Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x68);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_00134668(void **arg0, void *arg1, s32 n, Obj **args) {
    Handle h;
    void *o;
    func_00128470(&h, arg1);
    o = func_001324D8(h.p);
    func_00128418(&h, 2);
    func_0029EA18(&h, vcall(*args) != 0 ? -1 : func_004061F8(o));
    if ((void *)arg0 != (void *)&h) {
        void *p = h.p;
        if (p != 0) {
            func_002C0FE8(p);
        }
        if (*arg0 != 0) {
            func_002C1050(*arg0);
        }
        *arg0 = p;
    }
    func_0029CEF0(&h, 2);
}
