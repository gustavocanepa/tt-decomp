#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4690(s32, s32);                /* extern */

struct func_003890D8_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_003890D8(struct func_003890D8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = func_004A4690(0x40, 0x4000);
    arg0->unk0 = temp_v0;
    arg0->unk4 = (s32) (temp_v0 + 0x3000);
}
