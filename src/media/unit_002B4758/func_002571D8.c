#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002571D8_temp_a0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

struct func_002571D8_arg0 {
    char pad0[0x10C];
    s32 unk10C;
};

s32 func_002571D8(void *arg0) {
    struct func_002571D8_temp_a0 *temp_a0;

    temp_a0 = arg0 + (((struct func_002571D8_arg0 *)arg0)->unk10C * 0x10) + 0xEC;
    return (s32) (temp_a0->unk8 - temp_a0->unk4) >> 2;
}
