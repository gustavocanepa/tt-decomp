#include "types.h"
extern "C" void *func_00283D68(void *);
extern "C" void func_00283D10(void *, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

struct Obj {
    char pad0[0x10];
    s64 bits;
};
struct A {
    Obj *p;
    s32 pad[3];
};

extern "C" void func_00284358(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    A a;
    s32 b4[4];
    func_00283D68(&a);
    s32 *b = b4;
    func_0029EA18(b, (s32)(a.p->bits >> 6) & 7);
    if (arg0 != b) {
        s32 newVal = b[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        s32 oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(b, 2);
    func_00283D10(&a, 2);
}
