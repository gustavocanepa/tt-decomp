#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

struct func_001A1EE8_arg0 {
    s8 unk0;
    char pad1[0x1F];
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

s32 func_001A1EE8(struct func_001A1EE8_arg0 *arg0) {
    s32 temp_v0;

    arg0->unk0 = 0;
    temp_v0 = arg0->unk28;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    if (temp_v0 != 0) {
        arg0->unk28 = 0;
        func_004A45D0(temp_v0);
    }
}
