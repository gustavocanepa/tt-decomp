#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0038E308(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D02F0[];
extern char D_005D06C8[];
extern char D_005D0BB0[];
extern char D_005D13A0[];
extern char D_005D1450[];
struct func_00558DD0_temp_a0 {
    char pad0[0x14];
    s32 unk14;
};
struct func_00558DD0_temp_v0 {
    char pad0[0x14];
    s32 unk14;
};
struct func_00558DD0_temp_a0_2 {
    char pad0[0x14];
    s32 unk14;
};
struct func_00558DD0_temp_v1 {
    char pad0[0x14];
    s32 unk14;
};

struct func_00558DD0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_00558DD0(void *arg0, s32 arg1) {
    struct func_00558DD0_temp_a0 *temp_a0;
    struct func_00558DD0_temp_a0_2 *temp_a0_2;
    struct func_00558DD0_temp_v0 *temp_v0;
    struct func_00558DD0_temp_v1 *temp_v1;

    temp_a0 = arg0 + 0x154;
    ((struct func_00558DD0_arg0 *)arg0)->unk14 = (s32)D_005D02F0;
    temp_a0->unk14 = (s32)D_005D0BB0;
    func_0038E308(temp_a0, 0);
    temp_v0 = arg0 + 0xE4;
    temp_v0->unk14 = (s32)D_005D13A0;
    func_0038E308(temp_v0, 0);
    temp_a0_2 = arg0 + 0x78;
    temp_a0_2->unk14 = (s32)D_005D13A0;
    func_0038E308(temp_a0_2, 0);
    temp_v1 = arg0 + 0x40;
    temp_v1->unk14 = (s32)D_005D1450;
    func_0038E308(temp_v1, 0);
    ((struct func_00558DD0_arg0 *)arg0)->unk14 = (s32)D_005D06C8;
    func_0038E308(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
