#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003FBF40(s32, s32);                    /* extern */

struct func_005621D0_arg0 {
    s32 unk0;
    s32 unk4;
};

void *func_005621D0(struct func_005621D0_arg0 *arg0, s32 arg1) {
    arg0->unk4 = func_003FBF40(arg1, -1);
    arg0->unk0 = arg1;
    return arg0;
}
