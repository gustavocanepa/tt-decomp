#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0036F1D0();                            /* extern */

extern char D_005D2648[];
struct func_0036F1B0_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0036F1B0(struct func_0036F1B0_arg0 *arg0) {
    arg0->unk10 = (s32)D_005D2648;
    func_0036F1D0();
}
