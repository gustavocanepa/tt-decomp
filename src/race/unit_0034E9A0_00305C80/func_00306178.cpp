#include "types.h"

extern char D_005CFB50[];

extern "C" s32 func_002F04D8(s32 arg0, s32 arg1);
extern "C" void *func_00358B80(void *arg0);
extern "C" void RaceDisplayEventBase__put(void *o, void *t);

extern "C" void func_00306178(void **arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    if (*((u8 *)func_002F04D8((s32)arg0, arg1) + 0x752) == 0) {
        char *t = (char *)*arg0;
        if (*(s32 *)(t + 0xDC) == 0) {
            func_00358B80(sp);
            sp[1] = (s32)D_005CFB50;
            sp[0] = arg1;
            sp[2] = arg2;
            RaceDisplayEventBase__put(sp, t);
        }
    }
}
