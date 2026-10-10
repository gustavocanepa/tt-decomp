#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0026CD28(s32, s32);                /* extern */
s32 func_002A7958(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005C1398[];
struct func_0027FD30_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_0027FD30(void *arg0, s32 arg1) {
    ((struct func_0027FD30_arg0 *)arg0)->unk4 = (s32)D_005C1398;
    func_0026CD28(arg0 + 0x10, 2);
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x14, 4);
    }
}
