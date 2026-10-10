#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003EEBE8(s32);                             /* extern */
s32 func_003EF840(void *, s32);                 /* extern */

struct func_003EF888_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_003EF888(struct func_003EF888_arg0 *arg0) {
    func_003EF840(arg0, func_003EEBE8(arg0->unk4));
}
