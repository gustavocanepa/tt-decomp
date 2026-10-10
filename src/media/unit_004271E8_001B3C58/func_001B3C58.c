#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7618();                            /* extern */

extern char D_005AE170[];
struct func_001B3C58_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_001B3C58(struct func_001B3C58_arg0 *arg0, s32 arg1, s32 arg2) {
    func_002A7618();
    arg0->unk18 = arg2;
    arg0->unk10 = arg1;
    arg0->unk4 = (s32)D_005AE170;
    arg0->unk14 = 0;
}
