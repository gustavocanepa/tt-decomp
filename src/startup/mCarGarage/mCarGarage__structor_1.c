#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001315E0(void *, s32);                 /* extern */
s32 func_00132268(void *);                      /* extern */
s32 func_002A7618();                            /* extern */
s32 func_00405020(s32);                         /* extern */
s32 func_00411E18(void *);                      /* extern */
s32 exception__structor_0(s32);                         /* extern */

extern char D_005A63F8[];
struct mCarGarage__structor_1_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
};

void mCarGarage__structor_1(void *arg0, s32 arg1) {
    s32 temp_v0;

    func_002A7618();
    ((struct mCarGarage__structor_1_arg0 *)arg0)->unk4 = (s32)D_005A63F8;
    ((struct mCarGarage__structor_1_arg0 *)arg0)->unk10 = 1;
    temp_v0 = exception__structor_0(0x508);
    func_00405020(temp_v0);
    ((struct mCarGarage__structor_1_arg0 *)arg0)->unk14 = temp_v0;
    func_00411E18(arg0 + 0x18);
    func_00132268(arg0);
    func_001315E0(arg0, arg1);
}
