#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004E66B0_arg0 {
    char pad0[0x8];
    s32 unk8;
};
struct func_004E66B0_arg1 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_004E66B0(struct func_004E66B0_arg0 *arg0, struct func_004E66B0_arg1 *arg1) {
    return arg0->unk8 - arg1->unk8;
}
