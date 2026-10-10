#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00554228_arg0_unk6C {
    char pad0[0x80];
    s32 unk80;
};
struct func_00554228_arg0 {
    char pad0[0x6C];
    struct func_00554228_arg0_unk6C *unk6C;
};

s32 func_00554228(struct func_00554228_arg0 *arg0) {
    return arg0->unk6C->unk80;
}
