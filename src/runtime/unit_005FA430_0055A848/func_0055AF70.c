#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0055AF70_arg0_unk60 {
    char pad0[0x8];
    s32 unk8;
};
struct func_0055AF70_arg0 {
    char pad0[0x60];
    struct func_0055AF70_arg0_unk60 *unk60;
};

void func_0055AF70(struct func_0055AF70_arg0 *arg0, s32 arg1, s16 arg2) {
    M2C_FIELD(*(s32 *)((arg1 * 4) + arg0->unk60->unk8), s16 *, 0x117C) = arg2;
}
