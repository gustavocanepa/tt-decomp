#include "types.h"

struct Obj { char pad[0x20]; s32 p20; };

extern "C" s32 *func_00156538(s32 *arg0);
extern "C" s32 func_00198C78(s32 arg0);
extern "C" void func_0029EA18(s32 *arg0, s32 arg1);
extern "C" void func_0029CEF0(s32 *arg0, int arg1);
extern "C" void func_001564E0(s32 *arg0, int arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_00156D00(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1;
    s32 n;
    s32 newVal;
    s32 oldVal;

    func_00156538(buf0);
    n = func_00198C78(((Obj *)buf0[0])->p20);
    p1 = buf1;
    func_0029EA18(p1, n != 0);
    if (arg0 != p1) {
        newVal = *p1;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(p1, 2);
    func_001564E0(buf0, 2);
}
