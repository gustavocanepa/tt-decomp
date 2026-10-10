#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0042FB20(void *, s32, void *);         /* extern */

struct func_002E4C20_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x8];
    void *unk10;
};

void func_002E4C20(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    func_004F6678(arg0, 0, 0x4540);
    func_004F6678(arg3, 0, 0x1168);
    ((struct func_002E4C20_arg0 *)arg0)->unk4 = arg1;
    ((struct func_002E4C20_arg0 *)arg0)->unk0 = arg2;
    ((struct func_002E4C20_arg0 *)arg0)->unk10 = arg3;
    func_0042FB20(arg0 + 0x14, arg1, arg0);
}
