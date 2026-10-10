#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003BD100(s32);                             /* extern */
s32 func_003BD110(s32);                             /* extern */
s32 func_003BD120(s32);                             /* extern */
s32 func_003BD130(s32);                             /* extern */
s32 func_003BD140(s32);                             /* extern */
s32 func_003BD150(s32);                             /* extern */
s32 func_003BD1E0(s32);                             /* extern */
s32 func_003BD1F0(s32);                             /* extern */
s32 func_003BD200(s32);                             /* extern */
s32 func_003BD210(s32);                             /* extern */
s32 func_003BD408(s32);                             /* extern */
s32 func_003BD410(s32);                             /* extern */
s32 func_003BD558(s32 *, s32, s32);         /* extern */
s32 func_003BD900(s32);                             /* extern */
s32 func_003BD910(s32);                             /* extern */
s32 func_003BD940(s32);                             /* extern */
s32 func_003BD950(s32);                             /* extern */
s32 func_003D25A0(s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32 *, s32 *); /* extern */

struct func_003D35D0_arg0 {
    char pad0[0x100];
    f32 unk100;
    char pad104[0x1C];
    s32 unk120;
    char pad124[0x4];
    s32 unk128;
    s32 *unk12C;
};

void func_003D35D0(struct func_003D35D0_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 sp50;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    s32 sp6C;
    s32 sp70;
    s32 sp74;
    s32 sp78;
    s32 sp7C;
    s32 sp80;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 temp_fp;
    s32 temp_fp_2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 temp_s3_2;
    s32 temp_s4;
    s32 temp_s4_2;
    s32 temp_s5;
    s32 temp_s5_2;
    s32 temp_s6;
    s32 temp_s6_2;
    s32 temp_s7;
    s32 temp_s7_2;

    sp58 = arg1;
    sp50 = func_003BD408(*arg0->unk12C);
    sp54 = func_003BD410(*arg0->unk12C);
    temp_f20 = arg0->unk100;
    sp5C = func_003BD100(arg0->unk120);
    sp60 = func_003BD120(arg0->unk120);
    sp64 = func_003BD140(arg0->unk120);
    sp68 = func_003BD900(arg0->unk128);
    temp_s7 = func_003BD1E0(arg0->unk120);
    temp_s5 = func_003BD200(arg0->unk120);
    sp6C = func_003BD940(arg0->unk128);
    temp_fp = func_003BD110(arg0->unk120);
    temp_s6 = func_003BD130(arg0->unk120);
    temp_s4 = func_003BD150(arg0->unk120);
    temp_s3 = func_003BD910(arg0->unk128);
    temp_s2 = func_003BD1F0(arg0->unk120);
    temp_s1 = func_003BD210(arg0->unk120);
    func_003D25A0(0, fparg0, fparg1, temp_f20, fparg2, arg1, sp5C, sp60, sp64, sp68, temp_s7, temp_s5, sp6C, temp_fp, temp_s6, temp_s4, temp_s3, temp_s2, temp_s1, func_003BD950(arg0->unk128), &sp50, &sp54);
    temp_f20_2 = arg0->unk100;
    sp70 = func_003BD110(arg0->unk120);
    sp74 = func_003BD130(arg0->unk120);
    sp78 = func_003BD150(arg0->unk120);
    sp7C = func_003BD910(arg0->unk128);
    sp80 = func_003BD1F0(arg0->unk120);
    temp_fp_2 = func_003BD210(arg0->unk120);
    temp_s7_2 = func_003BD950(arg0->unk128);
    temp_s6_2 = func_003BD100(arg0->unk120);
    temp_s5_2 = func_003BD120(arg0->unk120);
    temp_s4_2 = func_003BD140(arg0->unk120);
    temp_s3_2 = func_003BD900(arg0->unk128);
    temp_s2_2 = func_003BD1E0(arg0->unk120);
    temp_s1_2 = func_003BD200(arg0->unk120);
    func_003D25A0(1, fparg0, fparg1, temp_f20_2, fparg2, sp58, sp70, sp74, sp78, sp7C, sp80, temp_fp_2, temp_s7_2, temp_s6_2, temp_s5_2, temp_s4_2, temp_s3_2, temp_s2_2, temp_s1_2, func_003BD940(arg0->unk128), &sp54, &sp50);
    func_003BD558(arg0->unk12C, 0, sp50);
    func_003BD558(arg0->unk12C, 1, sp54);
}
