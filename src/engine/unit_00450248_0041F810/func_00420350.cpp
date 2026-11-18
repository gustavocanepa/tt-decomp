#include "types.h"

struct Obj {
    char pad0[0x18];
    s32 handle;
};

extern "C" Obj *func_00420398(void);
extern "C" void func_00467728(Obj *p);
extern "C" void func_0046AE88(s32 h);

extern "C" s32 func_00420350(void) {
    Obj *p = func_00420398();
    if (p) {
        func_00467728(p);
        func_0046AE88(p->handle);
        return p->handle;
    }
    return 0;
}
