#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004130E8_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

s32 func_004130E8(struct func_004130E8_arg0 *arg0, s32 arg1) {
    if (arg1 >= arg0->unk4 || arg1 < 0) return 0;
    return arg0->unkC + (arg0->unk8 * arg1) + 4;
}
