#include "types.h"

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(bool);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_0025E6C0(void *arg0, int arg1);
extern "C" void func_0025E718(void *arg0, void *arg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029CF48(void *arg0, void *arg1);
extern "C" int func_0029E9F0(void *arg0);

static inline Obj *hget(Handle *h) { return h->p; }

static inline bool chk(Handle *ph, void *a3) {
    func_0029CF48(ph, a3);
    return func_0029E9F0(ph->p) != 0;
}

extern "C" void func_00542280(void *arg0, void *arg1, s32 arg2, void *arg3, PM pmf) {
    if (arg2 > 0) {
        Handle o;
        Handle h;
        Handle *po = &o;
        Handle *ph;
        func_0025E718(po, arg1);
        ph = &h;
        (hget(po)->*pmf)(chk(ph, arg3));
        func_0029CEF0(ph, 2);
        func_0025E6C0(po, 2);
    }
}
