/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F7B74(s32, s32);                    /* extern */

struct func_0037E308_arg2 {
    char pad0[0x14];
    s32 unk14;
};

void func_0037E308(s32 arg0, s32 arg1, struct func_0037E308_arg2 *arg2) {
    func_004F7B74(arg1, arg0 + (arg2->unk14 << 7) + 0x60);
}
