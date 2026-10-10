#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00357310(s32);                             /* extern */

struct func_00364E38_arg0 {
    char pad0[0x534];
    s32 unk534;
};

void func_00364E38(struct func_00364E38_arg0 *arg0, s32 arg1) {
    arg0->unk534 = func_00357310(arg1);
}
