#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00300070(s32, u8, s32);                /* extern */

struct func_002FDB00_arg0_unkC {
    char pad0[0x14C];
    s32 unk14C;
};
struct func_002FDB00_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    struct func_002FDB00_arg0_unkC *unkC;
    char pad10[0x554];
    u8 unk564;
};

void func_002FDB00(struct func_002FDB00_arg0 *arg0, s32 arg1) {
    func_00300070(arg0->unk4, arg0->unk564, arg0->unkC->unk14C + (arg1 * 0x4994));
}
