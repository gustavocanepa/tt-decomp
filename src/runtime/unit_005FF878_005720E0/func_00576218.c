#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00576218_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_00576218(struct func_00576218_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    arg0->unk4 = arg1;
    return temp_v0;
}
