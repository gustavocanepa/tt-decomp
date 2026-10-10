#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00386680(s32, s32);                    /* extern */

struct func_003868E8_temp_v0_unk60 {
    char pad0[0x8];
    s32 *unk8;
};
struct func_003868E8_temp_v0 {
    char pad0[0x60];
    struct func_003868E8_temp_v0_unk60 *unk60;
};

struct func_003868E8_arg0 {
    char pad0[0x6C];
    void *unk6C;
    char pad70[0xF080];
    s32 unkF0F0;
};

void func_003868E8(void *arg0) {
    struct func_003868E8_temp_v0 *temp_v0;

    temp_v0 = ((struct func_003868E8_arg0 *)arg0)->unk6C;
    if (temp_v0 != NULL) {
        func_00386680(arg0 + 0xEEE0, *temp_v0->unk60->unk8);
        ((struct func_003868E8_arg0 *)arg0)->unkF0F0 = 1;
    }
}
