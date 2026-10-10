#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002E3BD0(s32, s32, s32, s32);  /* extern */

struct ResultLinkBattle__virtual_04_arg0 {
    s32 unk0;
    char pad4[0x18];
    s32 unk1C;
    char pad20[0x340];
    s32 unk360;
    char pad364[0x4];
    s32 unk368;
};

s32 ResultArcade__render(struct ResultLinkBattle__virtual_04_arg0 *arg0) {
    s32 temp_a1;
    s32 temp_v1;

    if (arg0->unk1C != 0) {
        temp_v1 = arg0->unk360;
        if (temp_v1 != 0) {
            temp_a1 = arg0->unk368;
            if ((temp_a1 != 0) && (arg0->unk0 != 0)) {
                func_002E3BD0(temp_v1, temp_a1, 0x80FFFFFF, 0);
            }
        }
    }
}
