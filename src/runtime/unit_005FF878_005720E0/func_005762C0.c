#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005762C0_arg0 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_005762C0(struct func_005762C0_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk8;
    arg0->unk8 = arg1;
    return temp_v0;
}
