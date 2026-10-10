#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005720E0_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_005720E0(struct func_005720E0_arg0 *arg0) {
    return arg0->unk4 - arg0->unk0;
}
