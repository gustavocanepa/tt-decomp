#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */
s32 func_002C1148(s32);                         /* extern */

extern char D_005B7FA8[];
struct func_0022F730_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x14];
    s32 unk1C;
};

void func_0022F730(struct func_0022F730_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk4 = (s32)D_005B7FA8;
    temp_v1 = arg0->unk1C;
    if (temp_v1 != 0) {
        func_002C1148(temp_v1);
    }
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x20, 4);
    }
}
