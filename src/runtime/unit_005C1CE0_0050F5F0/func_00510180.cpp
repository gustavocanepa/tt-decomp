#include "types.h"

struct Obj {
    char pad0[4];
};

typedef void *(Obj::*PM)(void);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_00115090(void *arg0, int arg1);
extern "C" void func_001150E8(void *arg0, void *arg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);

static inline Obj *hget(Handle *h) { return h->p; }

extern "C" void func_00510180(void **arg0, void *arg1, s32 arg2, s32 arg3, PM pmf) {
    Handle h;
    Handle o;
    Handle *po = &o;

    func_001150E8(po, arg1);
    {
        void *r = (hget(po)->*pmf)();
        Handle *ph = &h;
        func_0029EA18(ph, r);
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
        func_0029CEF0(ph, 2);
    }
    func_00115090(po, 2);
}
