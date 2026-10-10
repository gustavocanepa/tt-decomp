#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004898A0(s32, s32);                    /* extern */

struct func_001A8AB8_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_001A8AB8(struct func_001A8AB8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 >= 0) {
        func_004898A0(arg0->unk0, temp_v0);
    }
    arg0->unk4 = -1;
}
