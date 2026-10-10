#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00555AA0_arg0_unk4 {
    char pad0[0xC0];
    s32 unkC0;
};
struct func_00555AA0_arg0 {
    char pad0[0x4];
    struct func_00555AA0_arg0_unk4 *unk4;
};

s32 func_00555AA0(struct func_00555AA0_arg0 *arg0) {
    return arg0->unk4->unkC0;
}
