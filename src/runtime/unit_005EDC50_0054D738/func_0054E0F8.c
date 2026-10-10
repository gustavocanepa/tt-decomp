#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0054E0F8_arg0 {
    char pad0[0x2C];
    void *unk2C;
};
struct func_0054E0F8_temp_a2 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x8];
    s32 unk14;
};

s32 func_0054E0F8(struct func_0054E0F8_arg0 *arg0, s32 arg1) {
    s32 temp_v1;
    struct func_0054E0F8_temp_a2 *temp_a2;

    temp_a2 = arg0->unk2C;
    temp_v1 = temp_a2->unk14 - arg1;
    temp_a2->unk14 = temp_v1;
    return temp_a2->unk8 + (temp_v1 * 4);
}
