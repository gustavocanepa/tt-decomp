#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);                     /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005BC860[];
struct func_00258B98_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00258B98(struct func_00258B98_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32)D_005BC860;
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x10, 4);
    }
}
