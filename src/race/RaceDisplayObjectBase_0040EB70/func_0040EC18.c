#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040EC60();                            /* extern */
s32 func_0040EC90(void *, s32);                 /* extern */

extern char D_005D97E8[];
struct func_0040EC18_arg0 {
    char pad0[0xB4];
    s32 unkB4;
};

void func_0040EC18(struct func_0040EC18_arg0 *arg0, s32 arg1) {
    arg0->unkB4 = (s32)D_005D97E8;
    func_0040EC60();
    func_0040EC90(arg0, arg1);
}
