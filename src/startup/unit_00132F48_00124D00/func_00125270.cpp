#include "types.h"

extern "C" void func_00123F00(void *arg0, int arg1);
extern "C" void *func_00123F58(void *arg0, void *arg1);
extern "C" void func_00139BB0(void *arg0, void *arg1);
extern "C" void func_00139BE0(void *arg0, int arg1);
extern "C" void *func_00139C38(void *arg0, void *arg1);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

extern "C" void func_00125270(void *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 newVal;
    s32 oldVal;

    if (arg2 > 0) {
        func_00123F58(buf0, arg1);
        if (*arg3 == 0) {
            s32 *p = buf1;
            s32 *pf = (s32 *)((char *)buf0[0] + 0x308);
            buf2[0] = 0;
            func_00139BB0(p, buf2);
            if (pf != p) {
                newVal = *p;
                if (newVal != 0) {
                    func_002C0FE8(newVal);
                }
                oldVal = *pf;
                if (oldVal != 0) {
                    func_002C1050(oldVal);
                }
                *pf = newVal;
            }
            func_00139BE0(p, 2);
        } else {
            s32 *p = buf1;
            func_00139C38(p, arg3);
            s32 *pf = (s32 *)((char *)buf0[0] + 0x308);
            if (pf != p) {
                newVal = *p;
                if (newVal != 0) {
                    func_002C0FE8(newVal);
                }
                oldVal = *pf;
                if (oldVal != 0) {
                    func_002C1050(oldVal);
                }
                *pf = newVal;
            }
            func_00139BE0(p, 2);
        }
        func_00123F00(buf0, 2);
    }
}
