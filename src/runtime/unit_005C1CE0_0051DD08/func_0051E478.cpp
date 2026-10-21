#include "types.h"

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(int);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_001940A0(void *arg0, int arg1);
extern "C" void func_001940F8(void *arg0, void *arg1);
extern "C" void func_002ADBF0(void *arg0, int arg1);
extern "C" void func_002ADC48(void *arg0, void *arg1);
extern "C" int func_002AFE68(void *arg0);

static inline Obj *hget(Handle *h) { return h->p; }

static inline int chk(Handle *ph, void *a3) {
    func_002ADC48(ph, a3);
    return func_002AFE68(ph->p);
}

extern "C" void func_0051E478(void *arg0, void *arg1, s32 arg2, void *arg3, PM pmf) {
    if (arg2 > 0) {
        Handle o;
        Handle h;
        Handle *po = &o;
        Handle *ph;
        func_001940F8(po, arg1);
        ph = &h;
        (hget(po)->*pmf)(chk(ph, arg3));
        func_002ADBF0(ph, 2);
        func_001940A0(po, 2);
    }
}
