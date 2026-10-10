#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00364200_temp_a0 {
    char pad0[0x18];
    s32 unk18;
};

void func_00364200(s32 arg0, s32 arg1) {
    struct func_00364200_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x88;
    temp_a0->unk18 = (s32) ((temp_a0->unk18 & 0xFF00FFFF) | ((arg1 & 0xFF) << 0x10));
}
