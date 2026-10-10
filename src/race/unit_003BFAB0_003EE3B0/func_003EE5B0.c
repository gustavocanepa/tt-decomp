#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004569D0();                            /* extern */

extern char D_005D74F8[];
struct func_003EE5B0_arg0 {
    char pad0[0x24];
    s32 unk24;
};

void func_003EE5B0(struct func_003EE5B0_arg0 *arg0) {
    func_004569D0();
    arg0->unk24 = (s32)D_005D74F8;
}
