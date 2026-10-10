#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001A8E30(void *, s32, s32);                /* extern */
s32 func_003EEB10(s32);                         /* extern */
void func_004161E0();                            /* extern */
s32 func_0041F840(s32);                         /* extern */

struct func_001A8ED0_temp_s1 {
    char pad0[0x40];
    s8 unk40;
    char pad41[0x3F];
    s8 unk80;
    char pad81[0x3F];
    s8 unkC0;
    char padC1[0x3F];
    s8 unk100;
    char pad101[0x3F];
    s8 unk140;
    char pad141[0x3F];
    s8 unk180;
    char pad181[0x3F];
    s8 unk1C0;
};

struct func_001A8ED0_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    char pad28[0x1F0];
    s8 unk218;
};

void func_001A8ED0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    struct func_001A8ED0_temp_s1 *temp_s1;

    if (((struct func_001A8ED0_arg0 *)arg0)->unk0 == 0) {
        ((struct func_001A8ED0_arg0 *)arg0)->unk4 = arg1;
        temp_s1 = arg0 + 0x218;
        if (((struct func_001A8ED0_arg0 *)arg0)->unk218 != 0) {
            temp_v0 = func_001A8E30(temp_s1, arg2, arg3);
            ((struct func_001A8ED0_arg0 *)arg0)->unk8 = temp_v0;
            func_0041F840(temp_v0);
        }
        if (temp_s1->unk40 != 0) {
            temp_v0_2 = func_001A8E30(arg0 + 0x258, arg2, arg3);
            ((struct func_001A8ED0_arg0 *)arg0)->unkC = temp_v0_2;
            func_0041F840(temp_v0_2);
        }
        if (temp_s1->unk80 != 0) {
            temp_v0_3 = func_001A8E30(arg0 + 0x298, arg2, arg3);
            ((struct func_001A8ED0_arg0 *)arg0)->unk10 = temp_v0_3;
            func_0041F840(temp_v0_3);
        }
        if (temp_s1->unkC0 != 0) {
            temp_v0_4 = func_001A8E30(arg0 + 0x2D8, arg2, arg3);
            ((struct func_001A8ED0_arg0 *)arg0)->unk18 = temp_v0_4;
            func_003EEB10(temp_v0_4);
        }
        if (temp_s1->unk100 != 0) {
            temp_v0_5 = func_001A8E30(arg0 + 0x318, arg2, arg3);
            ((struct func_001A8ED0_arg0 *)arg0)->unk1C = temp_v0_5;
            func_003EEB10(temp_v0_5);
        }
        if (temp_s1->unk140 != 0) {
            temp_v0_6 = func_001A8E30(arg0 + 0x358, arg2, arg3);
            ((struct func_001A8ED0_arg0 *)arg0)->unk24 = temp_v0_6;
            func_003EEB10(temp_v0_6);
        }
        if (temp_s1->unk180 != 0) {
            temp_v0_7 = func_001A8E30(arg0 + 0x398, arg2, arg3);
            ((struct func_001A8ED0_arg0 *)arg0)->unk20 = temp_v0_7;
            func_003EEB10(temp_v0_7);
        }
        if (temp_s1->unk1C0 != 0) {
            temp_v0_8 = func_001A8E30(arg0 + 0x3D8, arg2, arg3);
            ((struct func_001A8ED0_arg0 *)arg0)->unk14 = temp_v0_8;
            func_0041F840(temp_v0_8);
        }
        func_004161E0();
        ((struct func_001A8ED0_arg0 *)arg0)->unk0 = 1;
    }
}
