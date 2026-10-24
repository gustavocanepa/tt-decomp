#include "types.h"

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(int);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_00195358(void *arg0, int arg1);
extern "C" void func_001953B0(void *arg0, void *arg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029CF48(void *arg0, void *arg1);
extern "C" int func_0029E9F0(void *arg0);

static inline Obj *hget(Handle *h) { return h->p; }

static inline int chk(Handle *ph, void *a3) {
    func_0029CF48(ph, a3);
    return func_0029E9F0(ph->p);
}

extern "C" void func_0051F188(void *arg0, void *arg1, s32 arg2, void *arg3, PM pmf) {
    if (arg2 > 0) {
        Handle o;
        Handle h;
        Handle *po = &o;
        Handle *ph;
        func_001953B0(po, arg1);
        ph = &h;
        (hget(po)->*pmf)(chk(ph, arg3));
        func_0029CEF0(ph, 2);
        func_00195358(po, 2);
    }
}
