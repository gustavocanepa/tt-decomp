#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0019B400();                            /* extern */

extern char D_005AC688[];
struct func_005200A0_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    s32 unk50;
};

void func_005200A0(struct func_005200A0_arg0 *arg0) {
    func_0019B400();
    arg0->unk50 = 0;
    arg0->unk4C = (s32)D_005AC688;
}
