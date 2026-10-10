#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003EEBE8(s32);                             /* extern */
s32 func_003EF288(void *, s32);                 /* extern */

struct func_003EF2D0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_003EF2D0(struct func_003EF2D0_arg0 *arg0) {
    func_003EF288(arg0, func_003EEBE8(arg0->unk4));
}
