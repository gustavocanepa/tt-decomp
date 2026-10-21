#include "types.h"

extern "C" void func_001DF250(void *, void *);
extern "C" s32 func_001E2710(s32);
extern "C" void func_001DF1F8(void *, s32);
extern "C" void func_00202758(void *, s32 *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00202788(void *, s32);

extern "C" void MRenderContext__getPrelightWidget(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v;
    s32 newVal;
    s32 oldVal;
    func_001DF250(buf0, arg1);
    v = func_001E2710(buf0[0]);
    func_001DF1F8(buf0, 0x2);
    if (v == 0)
        return;
    buf1[0] = v;
    func_00202758(buf0, buf1);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_00202788(buf0, 0x2);
}
