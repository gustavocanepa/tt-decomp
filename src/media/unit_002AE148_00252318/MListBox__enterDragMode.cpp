#include "types.h"

extern "C" void func_00251678(void *);
extern "C" void func_001DF1C8(void *, void *);
extern "C" void func_00202758(void *, void *);
extern "C" void func_00257C60(s32, s32, s32);
extern "C" void func_00202788(void *, s32);
extern "C" void func_001DF1F8(void *, s32);
extern "C" void func_00251620(void *, s32);

extern "C" void MListBox__enterDragMode(void *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 t30;
    s32 t34;
    s32 *p1;
    s32 *p2;
    s32 *q30;
    s32 *q34;
    s32 v;

    if (arg2 == 0x2) {
        func_00251678(buf0);
        v = arg3[0];
        q30 = &t30;
        p1 = buf1;
        *q30 = v;
        func_001DF1C8(p1, q30);
        v = arg3[1];
        q34 = &t34;
        p2 = buf2;
        *q34 = v;
        func_00202758(p2, q34);
        func_00257C60(buf0[0], p1[0], p2[0]);
        func_00202788(p2, 0x2);
        func_001DF1F8(p1, 0x2);
        func_00251620(buf0, 0x2);
    }
}
