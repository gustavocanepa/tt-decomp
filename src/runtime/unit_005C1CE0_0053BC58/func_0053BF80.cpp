#include "types.h"

struct Obj {
    char pad0[4];
};

typedef float (Obj::*PM)(void);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_0023E7B8(void *arg0, int arg1);
extern "C" void func_0023E810(void *arg0, void *arg1);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_0029B380(void *arg0, float arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);

static inline Obj *hget(Handle *h) { return h->p; }

extern "C" void func_0053BF80(void **arg0, void *arg1, s32 arg2, s32 arg3, PM pmf) {
    Handle h;
    Handle o;
    Handle *po = &o;

    func_0023E810(po, arg1);
    {
        float r = (hget(po)->*pmf)();
        Handle *ph = &h;
        func_0029B380(ph, r);
        if ((void *)arg0 != (void *)ph) {
            void *p = ph->p;
            if (p != 0) {
                func_002C0FE8(p);
            }
            if (*arg0 != 0) {
                func_002C1050(*arg0);
            }
            *arg0 = p;
        }
        func_00299AB0(ph, 2);
    }
    func_0023E7B8(po, 2);
}
