#include "types.h"

extern "C" void func_00251620(void *arg0, int arg1);
extern "C" void func_00251678(void *arg0, void *arg1);
extern "C" void func_00257068(void *arg0, char *arg1);
extern "C" void func_00257098(char *arg0, void *arg1);
extern "C" void func_002A75A8(void *arg0, int arg1);
extern "C" void func_002A7590(void *arg0, void *arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_00253268(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    char *h[4];
    if (arg2 == 0) {
        s32 buf[4];
        s32 *buf0;
        s32 newVal;
        s32 oldVal;
        func_00251678(h, arg1);
        buf0 = buf;
        func_00257068(buf0, h[0]);
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
        func_002A75A8(buf0, 2);
        func_00251620(h, 2);
    } else if (arg2 == 1) {
        s32 buf2[4];
        s32 *p2;
        func_00251678(h, arg1);
        p2 = buf2;
        func_002A7590(p2, arg3);
        func_00257098(h[0], p2);
        func_002A75A8(p2, 2);
        func_00251620(h, 2);
    }
}
