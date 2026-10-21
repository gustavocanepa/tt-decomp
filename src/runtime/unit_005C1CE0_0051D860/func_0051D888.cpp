#include "types.h"

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(void);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_00187118(void *arg0, int arg1);
extern "C" void func_00187170(void *arg0, void *arg1);

static inline Obj *hget(Handle *h) { return h->p; }

extern "C" void func_0051D888(void *arg0, void *arg1, s32 arg2, s32 arg3, PM pmf) {
    Handle o;
    Handle *po = &o;

    func_00187170(po, arg1);
    (hget(po)->*pmf)();
    func_00187118(po, 2);
}
