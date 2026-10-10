#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040BBD0();                            /* extern */

extern char D_005D1560[];
struct func_003690B0_arg0 {
    char pad0[0x190];
    s32 unk190;
    s32 unk194;
};

void func_003690B0(struct func_003690B0_arg0 *arg0) {
    func_0040BBD0();
    arg0->unk190 = 0;
    arg0->unk194 = (s32)D_005D1560;
}
