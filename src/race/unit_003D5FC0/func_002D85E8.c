/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002D8830(void *, s32);                 /* extern */
s32 func_002D8C18(void *, s32);             /* extern */
s32 func_002D8FB0(void *);                      /* extern */
s32 func_002D9000(void *);                      /* extern */
s32 func_003EB018(s32);                             /* extern */
s32 func_003EB020(s32);                             /* extern */

struct func_002D85E8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    char pad24[0x20];
    s32 unk44;
    char pad48[0x14];
    s32 unk5C;
    char pad60[0x10];
    s32 unk70;
    char pad74[0x1C];
    s32 unk90;
    char pad94[0x8];
    s32 unk9C;
    char padA0[0x4];
    s32 unkA4;
};

void func_002D85E8(struct func_002D85E8_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    if ((arg0->unk1C != 0) && (arg0->unk20 == 0)) {
        temp_v0 = func_003EB020(arg1);
        if (temp_v0 & 1) {
            func_002D8C18(arg0, (arg0->unk44 == 0) ? 0 : 2);
        }
        if (func_003EB018(arg1) & 0x80) {
            if (temp_v0 & 0x80) {
                arg0->unk90 = 0;
                arg0->unk9C = 2;
            }
            arg0->unk5C = 1;
            if (temp_v0 & 0x100) {
                func_002D9000(arg0);
            }
            if (temp_v0 & 0x200) {
                func_002D8FB0(arg0);
            }
        } else if (arg0->unk5C != 0) {
            arg0->unk5C = 0;
            arg0->unkA4 = (s32) ((arg0->unkA4 & ~0xFF) | 1);
        }
        if (temp_v0 & 0xC00) {
            arg0->unk9C = 2;
            arg0->unk70 = (s32) (arg0->unk70 ^ 1);
            arg0->unkA4 = (s32) ((arg0->unkA4 & ~0xFF) | 1);
        }
        func_002D8830(arg0, arg1);
    }
}
