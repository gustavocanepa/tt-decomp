#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00182C28_arg0_unkB4 {
    char pad0[0x2BC];
    s32 unk2BC;
};
struct func_00182C28_arg0 {
    char pad0[0xB4];
    struct func_00182C28_arg0_unkB4 *unkB4;
};

s32 func_00182C28(struct func_00182C28_arg0 *arg0) {
    return arg0->unkB4->unk2BC;
}
