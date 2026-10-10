#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004898A0(s32, s32);                    /* extern */

struct func_0028D888_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x4];
    s32 unk20;
};

void func_0028D888(struct func_0028D888_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk20;
    if (temp_v0 >= 0) {
        func_004898A0(arg0->unk18, temp_v0);
    }
    arg0->unk20 = -1;
}
