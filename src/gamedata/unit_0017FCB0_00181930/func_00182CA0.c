#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00182CA0_arg0_unkB4 {
    char pad0[0x1C];
    s32 unk1C;
};
struct func_00182CA0_arg0 {
    char pad0[0xB4];
    struct func_00182CA0_arg0_unkB4 *unkB4;
};

void func_00182CA0(struct func_00182CA0_arg0 *arg0, s32 arg1) {
    arg0->unkB4->unk1C = arg1;
}
