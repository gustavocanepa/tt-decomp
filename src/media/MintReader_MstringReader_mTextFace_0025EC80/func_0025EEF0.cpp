#include "types.h"

extern "C" void func_0025E6C0(void *arg0, int arg1);
extern "C" void func_0025E718(void *arg0, void *arg1);
extern "C" s32 func_00261F78(char *arg0);
extern "C" void func_002ADBF0(void *arg0, int arg1);
extern "C" void func_002B01F8(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_0025EEF0(s32 *arg0, void *arg1, s32 arg2) {
    char *h[4];
    if (arg2 == 0) {
        s32 buf[4];
        s32 *buf0;
        s32 newVal;
        s32 oldVal;
        s32 v;
        func_0025E718(h, arg1);
        v = func_00261F78(h[0]);
        buf0 = buf;
        func_002B01F8(buf0, v);
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
        func_002ADBF0(buf0, 2);
        func_0025E6C0(h, 2);
    }
}
