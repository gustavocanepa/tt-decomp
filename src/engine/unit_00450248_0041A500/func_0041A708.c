#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041E318(s32, s32, s32);           /* extern */

struct func_0041A708_arg0 {
    s32 unk0;
    char pad4[0x5E4];
    s32 unk5E8;
};

s32 func_0041A708(struct func_0041A708_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk5E8;
    if (temp_v0 != 0) {
        func_0041E318(arg0->unk0, temp_v0, 1);
    }
}
