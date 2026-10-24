#include "types.h"

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(float);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_00218280(void *arg0, int arg1);
extern "C" void func_002182D8(void *arg0, void *arg1);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_00299B08(void *arg0, void *arg1);
extern "C" float func_0029B188(void *arg0);

static inline Obj *hget(Handle *h) { return h->p; }

static inline float chk(Handle *ph, void *a3) {
    func_00299B08(ph, a3);
    return func_0029B188(ph->p);
}

extern "C" void func_005354F8(void *arg0, void *arg1, s32 arg2, void *arg3, PM pmf) {
    if (arg2 > 0) {
        Handle o;
        Handle h;
        Handle *po = &o;
        Handle *ph;
        func_002182D8(po, arg1);
        ph = &h;
        (hget(po)->*pmf)(chk(ph, arg3));
        func_00299AB0(ph, 2);
        func_00218280(po, 2);
    }
}
