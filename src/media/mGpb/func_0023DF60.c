#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */
s32 func_0045D8D8(s32, s32);                /* extern */
s32 func_0045DA70(s32);                         /* extern */

extern char D_005B9C30[];
struct func_0023DF60_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_0023DF60(void *arg0, s32 arg1) {
    s32 temp_s2;

    temp_s2 = arg0 + 0x10;
    ((struct func_0023DF60_arg0 *)arg0)->unk4 = (s32)D_005B9C30;
    func_0045DA70(temp_s2);
    func_0045D8D8(temp_s2, 2);
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x18, 4);
    }
}
