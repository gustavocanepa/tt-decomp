#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7618();                            /* extern */

extern char D_005A7180[];
struct func_001421C0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
};

s32 func_001421C0(struct func_001421C0_arg0 *arg0, s32 arg1, s32 arg2) {
    func_002A7618();
    arg0->unk14 = arg2;
    arg0->unk10 = arg1;
    arg0->unk4 = (s32)D_005A7180;
}
