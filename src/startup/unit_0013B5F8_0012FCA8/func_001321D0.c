#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004394E8(s32, f32);                /* extern */

extern char D_005865D0[];
struct func_001321D0_arg0 {
    char pad0[0x180];
    s32 unk180;
};

void func_001321D0(struct func_001321D0_arg0 *arg0) {
    func_004394E8((s32)D_005865D0, (f32) arg0->unk180 / 0x1.9000000000000p+6f);
}
