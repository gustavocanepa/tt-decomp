#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00216AA0_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_00216AA0(struct func_00216AA0_arg0 *arg0, s32 arg1) {
    if (arg1 < arg0->unk4) {
        return arg0->unk8 + (arg1 << 5) + 4;
    }
    return 0;
}
