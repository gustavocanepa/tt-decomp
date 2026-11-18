#include "types.h"

struct Obj {
    char pad0[0x3E8];
    void *p3E8;
    char pad1[0x404 - 0x3EC];
    s32 f404;
};

extern s32 D_005A07FC;
extern s32 D_005A07F8;

extern "C" void func_004AEAC0(void *arg0);
extern "C" void func_004AEAF8(void *arg0);
extern "C" void func_004BDB58(void *arg0);
extern "C" void func_004FA840(s32 arg0);
extern "C" s32 func_004FA860(s32 arg0);

extern "C" s32 func_004BCAA0(Obj *arg0, s32 arg1) {
    s32 var_s1 = arg1;

    if (var_s1 != 0) {
        func_004AEAC0((char *)arg0 + 0x2C0);
    }
    func_004FA860(D_005A07FC);
    if (arg0->f404 != 0) {
        arg0->f404 = 3;
        func_004BDB58(arg0->p3E8);
        D_005A07F8 = 1;
    } else {
        var_s1 = 0;
    }
    func_004FA840(D_005A07FC);
    if (var_s1 != 0) {
        func_004AEAF8((char *)arg0 + 0x2C0);
    }
    return 0;
}
