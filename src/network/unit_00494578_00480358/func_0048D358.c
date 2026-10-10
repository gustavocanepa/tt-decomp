#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0048F4A0();                                /* extern */
s32 func_0048D3E0(void *, s32, s32, s32);       /* extern */

extern char D_0048D3E0[];
struct func_0048D358_arg0 {
    char pad0[0x120];
    s32 unk120;
};

void func_0048D358(struct func_0048D358_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_0048F4A0() == 0) {
        arg0->unk120 = (s32)D_0048D3E0;
        func_0048D3E0(arg0, arg1, arg2, arg3);
    }
}
