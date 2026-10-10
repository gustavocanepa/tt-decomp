#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);        /* extern */

extern char D_005B9550[];
struct func_0023D528_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xBC];
    s32 unkC4;
};
struct func_0023D528_temp_v1 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_0023D528(struct func_0023D528_arg0 *arg0, s32 arg1) {
    s32 temp_v0;
    struct func_0023D528_temp_v1 *temp_v1;

    arg0->unk4 = (s32)D_005B9550;
    temp_v1 = arg0->unkC4 - 0x10;
    temp_v0 = temp_v1->unk8 - 1;
    temp_v1->unk8 = temp_v0;
    if (temp_v0 == 0) {
        func_002BDA70(temp_v1, temp_v1->unk4 + 0x10, 4);
    }
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0xC8, 4);
    }
}
