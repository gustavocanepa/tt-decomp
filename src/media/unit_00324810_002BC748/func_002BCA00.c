#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A48C0(s32);                         /* extern */

struct func_002BCA00_arg0 {
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
};

void func_002BCA00(void *arg0, s32 arg1, s32 arg2) {
    ((struct func_002BCA00_arg0 *)arg0)->unk10 = arg1;
    ((struct func_002BCA00_arg0 *)arg0)->unk0 = 0;
    ((struct func_002BCA00_arg0 *)arg0)->unk4 = 0;
    ((struct func_002BCA00_arg0 *)arg0)->unk8 = 0;
    ((struct func_002BCA00_arg0 *)arg0)->unkC = 0;
    ((struct func_002BCA00_arg0 *)arg0)->unk14 = arg2;
    ((struct func_002BCA00_arg0 *)arg0)->unk18 = arg2;
    ((struct func_002BCA00_arg0 *)arg0)->unk1C = 0x32;
    ((struct func_002BCA00_arg0 *)arg0)->unk20 = 0;
    ((struct func_002BCA00_arg0 *)arg0)->unk24 = 0;
    func_004A48C0(arg0 + 0x28);
}
