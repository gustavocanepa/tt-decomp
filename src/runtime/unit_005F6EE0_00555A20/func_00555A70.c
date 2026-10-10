#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00555A70_arg0_unk4 {
    char pad0[0xB0];
    s32 unkB0;
};
struct func_00555A70_arg0 {
    char pad0[0x4];
    struct func_00555A70_arg0_unk4 *unk4;
};

s32 func_00555A70(struct func_00555A70_arg0 *arg0) {
    return arg0->unk4->unkB0;
}
