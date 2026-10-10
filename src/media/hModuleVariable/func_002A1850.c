#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002A0420(s32, s32);                    /* extern */
s32 func_002A7590(void *, s32);                 /* extern */
s32 func_002A7618();                            /* extern */

extern char D_005C4F30[];
struct func_002A1850_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_002A1850(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_002A7618();
    ((struct func_002A1850_arg0 *)arg0)->unk4 = (s32)D_005C4F30;
    func_002A0420(arg0 + 0x10, arg1);
    func_002A7590(arg0 + 0x14, arg2);
}
