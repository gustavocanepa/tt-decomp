#include "types.h"

struct RefCounter;

extern "C" void func_002B2030(void *arg0);
extern "C" s32 hThread__execCode(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);
extern "C" void func_002B1578(void *arg0, int arg1);
extern "C" void func_002A75A8(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void hScriptMethod__call_const(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s5;
    s32 newVal;
    s32 oldVal;

    func_002B2030(buf0);
    p_s5 = buf1;
    hThread__execCode(p_s5, buf0[0], (char *)arg0 + 0xC, arg2, arg3, arg4);
    if (arg1 != p_s5) {
        newVal = *p_s5;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *arg1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *arg1 = newVal;
    }
    func_002A75A8(p_s5, 2);
    func_002B1578(buf0, 2);
}
