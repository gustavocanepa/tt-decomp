#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct RaceNetBattle__virtual_132_arg0 {
    char pad0[0xE4E4];
    void *unkE4E4;
};
struct RaceNetBattle__virtual_132_temp_a0 {
    char pad0[0x28];
    s32 unk28;
    char pad2C[0x54];
    f32 unk80;
};

s32 RaceBasic__isCrossFadeEnabled(struct RaceNetBattle__virtual_132_arg0 *arg0) {
    s32 var_a1;
    struct RaceNetBattle__virtual_132_temp_a0 *temp_a0;

    temp_a0 = arg0->unkE4E4;
    if (temp_a0 != NULL) {
        var_a1 = 0;
        if ((temp_a0->unk28 != 1) && (temp_a0->unk80 == -0x1.0000000000000p+0f)) {
            var_a1 = 1;
        }
        return var_a1;
    }
    return 1;
}
