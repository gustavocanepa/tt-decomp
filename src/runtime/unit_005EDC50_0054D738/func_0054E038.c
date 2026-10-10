#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0054E038_arg0 {
    char pad0[0x2C];
    void *unk2C;
};
struct func_0054E038_temp_s2 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x8];
    s32 unk14;
};

void func_0054E038(struct func_0054E038_arg0 *arg0, s32 *arg1) {
    s32 *temp_s1;
    s32 temp_s0;
    s32 temp_v0;
    struct func_0054E038_temp_s2 *temp_s2;

    temp_s2 = arg0->unk2C;
    temp_s1 = temp_s2->unk8 + (temp_s2->unk14 * 4);
    if (temp_s1 != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_v0 = *temp_s1;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        *temp_s1 = temp_s0;
    }
    temp_s2->unk14 = (s32) (temp_s2->unk14 + 1);
}
