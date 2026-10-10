#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00338F80();                            /* extern */

extern char D_005CC1D8[];
struct func_003398D8_arg0 {
    char pad0[0x134];
    s32 unk134;
    char pad138[0x198];
    s64 unk2D0;
    s32 unk2D8;
};

void func_003398D8(struct func_003398D8_arg0 *arg0) {
    func_00338F80();
    arg0->unk2D8 = 0;
    arg0->unk2D0 = 0;
    arg0->unk134 = (s32)D_005CC1D8;
}
