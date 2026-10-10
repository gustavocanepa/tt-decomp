#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0035D560_temp_a3 {
    char pad0[0x34];
    s32 unk34;
};
struct func_0035D560_temp_a0 {
    char pad0[0x54];
    s32 unk54;
};

void func_0035D560(s32 arg0, s32 arg1) {
    s32 temp_a1;
    struct func_0035D560_temp_a0 *temp_a0;
    struct func_0035D560_temp_a3 *temp_a3;

    temp_a3 = arg0 + 0x128;
    temp_a0 = arg0 + 0x160;
    temp_a1 = (arg1 & 0xFF) << 0x10;
    temp_a3->unk34 = (s32) ((temp_a3->unk34 & 0xFF00FFFF) | temp_a1);
    temp_a0->unk54 = (s32) ((temp_a0->unk54 & 0xFF00FFFF) | temp_a1);
}
