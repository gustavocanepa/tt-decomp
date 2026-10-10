#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 DynamicsConductor__structor_1(void *, s32);             /* extern */
s32 func_00370E78(void *, s32);             /* extern */
s32 func_00371730();                            /* extern */
s32 func_00371DE8(void *, s32);             /* extern */
s32 RacePause__structor_1(void *, s32);             /* extern */
s32 func_0037FB98(void *, s32);             /* extern */
s32 func_00386198(void *, s32);             /* extern */
s32 LicenseConcourse__structor_1(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D2760[];
extern char D_005D6548[];
struct DynamicsConductorLicense__structor_0_temp_v1 {
    char pad0[0x241CC];
    s32 unk241CC;
};

struct DynamicsConductorLicense__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void DynamicsConductorLicense__structor_0(void *arg0, s32 arg1) {
    struct DynamicsConductorLicense__structor_0_temp_v1 *temp_v1;

    ((struct DynamicsConductorLicense__structor_0_arg0 *)arg0)->unk64 = (s32)D_005D2760;
    func_00371730();
    LicenseConcourse__structor_1(arg0 + 0x3A8C0, 2);
    func_0037FB98(arg0 + 0x39F90, 2);
    temp_v1 = arg0 + 0x15DC0;
    temp_v1->unk241CC = (s32)D_005D6548;
    DynamicsConductor__structor_1(temp_v1, 0);
    func_00371DE8(arg0 + 0x104A8, 2);
    func_00370E78(arg0 + 0xF2B8, 2);
    RacePause__structor_1(arg0 + 0xF280, 2);
    func_00386198(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
