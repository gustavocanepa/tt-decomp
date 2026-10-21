#include "types.h"
#define NULL 0

struct func_001068C8_arg {
    char pad0[0x78];
    s32 unk78;
};

void func_001068C8(s8 *arg0) {
    s8 *temp_a1 = arg0 + 0x44;
    s32 one = 1;
    s8 *temp_a2 = arg0 + 0xC0;
    s8 *e;

    e = temp_a1 + (((struct func_001068C8_arg *)temp_a1)->unk78 * 0x3C);
    *(s32 *)(e + 0x30) = 0;
    temp_a1 = temp_a1 + ((one - ((struct func_001068C8_arg *)temp_a1)->unk78) * 0x3C);
    *(s32 *)(temp_a1 + 0x30) = 0;
    e = temp_a2 + (((struct func_001068C8_arg *)temp_a2)->unk78 * 0x3C);
    *(s32 *)(e + 0x30) = 0;
    temp_a2 = temp_a2 + ((one - ((struct func_001068C8_arg *)temp_a2)->unk78) * 0x3C);
    *(s32 *)(temp_a2 + 0x30) = 0;
    *(s32 *)(arg0 + 0x16C) = 0;
}
