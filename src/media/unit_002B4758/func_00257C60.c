#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00257B00();                            /* extern */

struct func_00257C60_arg0 {
    char pad0[0x14C];
    s32 unk14C;
    char pad150[0x4];
    s32 unk154;
    char pad158[0x1C];
    s32 unk174;
};

void func_00257C60(struct func_00257C60_arg0 *arg0) {
    func_00257B00();
    arg0->unk174 = 2;
    arg0->unk154 = (s32) arg0->unk14C;
}
