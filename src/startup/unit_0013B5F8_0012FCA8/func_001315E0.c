#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00408720(s32);                             /* extern */
s32 func_00408C18(s32, s32);                /* extern */

struct func_001315E0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_001315E0(struct func_001315E0_arg0 *arg0) {
    s32 temp_s1;

    temp_s1 = func_00408720(arg0->unk14);
    func_00408C18(arg0->unk14, 0);
    return temp_s1;
}
