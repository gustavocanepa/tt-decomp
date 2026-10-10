#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0043E0F8(s32);                             /* extern */

struct func_00441790_arg0 {
    char pad0[0x74];
    s32 unk74;
};

void func_00441790(struct func_00441790_arg0 *arg0, s32 arg1) {
    arg0->unk74 = func_0043E0F8(arg1);
}
