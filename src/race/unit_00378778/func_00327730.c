#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003216C0();                            /* extern */

extern char D_005CA5E0[];
struct func_00327730_arg0 {
    s32 unk0;
    char pad4[0x188];
    s32 unk18C;
};

void func_00327730(struct func_00327730_arg0 *arg0) {
    func_003216C0();
    arg0->unk18C = 0;
    arg0->unk0 = (s32)D_005CA5E0;
}
