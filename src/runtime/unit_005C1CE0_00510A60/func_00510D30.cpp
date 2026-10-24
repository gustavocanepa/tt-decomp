#include "types.h"

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(void);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_0011C8C0(void *arg0, int arg1);
extern "C" void func_0011C918(void *arg0, void *arg1);

static inline Obj *hget(Handle *h) { return h->p; }

extern "C" void func_00510D30(void *arg0, void *arg1, s32 arg2, s32 arg3, PM pmf) {
    Handle o;
    Handle *po = &o;

    func_0011C918(po, arg1);
    (hget(po)->*pmf)();
    func_0011C8C0(po, 2);
}
