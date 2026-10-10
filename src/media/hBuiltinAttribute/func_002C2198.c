#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002BC190();                            /* extern */

extern char D_005C7B48[];
struct func_002C2198_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    s32 unk10;
};

s32 func_002C2198(struct func_002C2198_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_002BC190();
    arg0->unk10 = arg3;
    arg0->unkC = arg2;
    arg0->unk4 = (s32)D_005C7B48;
}
