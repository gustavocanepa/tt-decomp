#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001035D8();                            /* extern */

extern char D_005A4A88[];
struct func_001042F0_arg0 {
    s32 unk0;
    char pad4[0x40];
    s32 unk44;
};

void func_001042F0(struct func_001042F0_arg0 *arg0) {
    func_001035D8();
    arg0->unk44 = 0;
    arg0->unk0 = (s32)D_005A4A88;
}
