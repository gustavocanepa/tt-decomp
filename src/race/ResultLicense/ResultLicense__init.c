/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0037D610();                            /* extern */
s32 func_0037FA98(s32);                             /* extern */
s32 func_0037FCE0(void *);                      /* extern */
s32 GranTurismo4__GetTimeString(s32, void *, s32);    /* extern */

struct ResultLicense__virtual_01_arg1 {
    char pad0[0x70];
    s32 unk70;
};

struct ResultLicense__virtual_01_arg0 {
    char pad0[0x850];
    s8 unk850;
    char pad851[0x23];
    f32 unk874;
    s32 unk878;
    s32 unk87C;
    s32 unk880;
};

void ResultLicense__init(void *arg0, struct ResultLicense__virtual_01_arg1 *arg1) {
    s32 temp_v0;

    func_0037D610();
    temp_v0 = func_0037FA98(arg1->unk70);
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk87C = 0;
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk878 = temp_v0;
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk880 = 0;
    GranTurismo4__GetTimeString(0x157529FF, arg0 + 0x378, 0x20);
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk850 = 0;
    ((struct ResultLicense__virtual_01_arg0 *)arg0)->unk874 = 0x1.0000000000000p+0f;
    func_0037FCE0(arg0);
}
