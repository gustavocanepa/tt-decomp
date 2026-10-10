#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char func_005540A0[];
extern char func_005541A0[];
s32 GT4MC__FileGT4GameData__loadInstance(s32, s32, s32, void *, void *, void *);
struct func_003757B0_arg0 {
    char pad0[0x84];
    void *unk84;
};
struct func_003757B0_temp_v0 {
    s16 unk0;
    char pad2[0x2];
    s32 unk4;
};

struct func_003757B0_temp_v1 {
    char pad0[0x64];
    void *unk64;
};

s32 RaceOrganization__validArcadeOption(struct func_003757B0_arg0 *arg0) {
    struct func_003757B0_temp_v0 *temp_v0;
    s8 *temp_v1;
    temp_v1 = arg0->unk84;
    if (temp_v1 != NULL) {
        temp_v0 = ((struct func_003757B0_temp_v1 *)temp_v1)->unk64;
        return GT4MC__FileGT4GameData__loadInstance(temp_v0->unk4, (s32)func_005540A0, 0, temp_v1 + temp_v0->unk0, func_005541A0, temp_v1) != 0;
    }
    return 0;
}
