#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0022F730(void *, s32);                     /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005B7858[];
struct func_005411F0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_005411F0(struct func_005411F0_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32)D_005B7858;
    func_0022F730(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x20, 4);
    }
}
