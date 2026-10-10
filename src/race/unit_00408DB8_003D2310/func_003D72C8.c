#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 *func_003BD070(s32);                            /* extern */
s32 *func_003BD080(s32);                            /* extern */
s32 *func_003BD090(s32);                            /* extern */
s32 *func_003BD0C0(s32);                            /* extern */

struct func_003D72C8_arg0 {
    char pad0[0x120];
    s32 unk120;
};

void func_003D72C8(struct func_003D72C8_arg0 *arg0) {
    *func_003BD070(arg0->unk120) = 0;
    *func_003BD0C0(arg0->unk120) = 0;
    *func_003BD080(arg0->unk120) = 0;
    *func_003BD090(arg0->unk120) = 0;
}
