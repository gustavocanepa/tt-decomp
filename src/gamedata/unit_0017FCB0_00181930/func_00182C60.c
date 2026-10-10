#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00182C60_arg0_unkB4 {
    char pad0[0x8];
    s32 unk8;
};
struct func_00182C60_arg0 {
    char pad0[0xB4];
    struct func_00182C60_arg0_unkB4 *unkB4;
};

void func_00182C60(struct func_00182C60_arg0 *arg0, s32 arg1) {
    arg0->unkB4->unk8 = arg1;
}
