#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00566038_arg0_unkC {
    char pad0[0x4];
    s32 unk4;
};
struct func_00566038_arg0 {
    char pad0[0xC];
    struct func_00566038_arg0_unkC *unkC;
};

s32 func_00566038(struct func_00566038_arg0 *arg0) {
    return arg0->unkC->unk4;
}
