#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_002E8A48(s32);                           /* extern */

struct func_00369730_arg0_unk5450 {
    char pad0[0x144];
    s32 unk144;
};
struct func_00369730_arg0 {
    char pad0[0x12AC];
    s32 unk12AC;
    char pad12B0[0x41A0];
    struct func_00369730_arg0_unk5450 *unk5450;
};
struct func_00369730_temp_v0 {
    char pad0[0x10];
    s32 unk10;
};

void func_00369730(struct func_00369730_arg0 *arg0) {
    s32 temp_v1;
    struct func_00369730_temp_v0 *temp_v0;

    temp_v1 = arg0->unk5450->unk144;
    if (temp_v1 != 0) {
        temp_v0 = func_002E8A48(temp_v1);
        if (temp_v0 != NULL) {
            arg0->unk12AC = (s32) temp_v0->unk10;
        }
    }
}
