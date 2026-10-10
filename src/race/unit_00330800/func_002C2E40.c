#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_002C2E40_arg0 {
    s32 *unk0;
    f32 unk4;
    f32 unk8;
};

f32 func_002C2E40(struct func_002C2E40_arg0 *arg0) {
    return arg0->unk4 / ((1.0f - ((f32) (*arg0->unk0 & 0xFFFFFF) * 1.1920929e-7f)) + arg0->unk8);
}
