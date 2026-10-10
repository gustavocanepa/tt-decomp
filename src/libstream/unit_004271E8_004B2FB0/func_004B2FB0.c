#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RefCounter__structor_0();                            /* extern */

extern char D_005DAEE0[];
struct func_004B2FB0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x80];
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
};

void func_004B2FB0(struct func_004B2FB0_arg0 *arg0, s32 arg1, s32 arg2) {
    RefCounter__structor_0();
    arg0->unkA0 = arg1;
    arg0->unkA4 = arg2;
    arg0->unk1C = (s32)D_005DAEE0;
    arg0->unkA8 = 0;
    arg0->unkAC = 0;
}
