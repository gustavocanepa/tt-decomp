#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00412828();                                /* extern */

struct func_00412738_arg0 {
    char pad0[0x4];
    s32 *unk4;
};

s32 func_00412738(struct func_00412738_arg0 *arg0, s32 arg1) {
    *arg0->unk4 = arg1;
    return func_00412828() != 0;
}
