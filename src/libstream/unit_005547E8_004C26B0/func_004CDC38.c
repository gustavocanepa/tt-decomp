#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA840(s32);                         /* extern */
s32 func_004FA860(s32);                         /* extern */

struct func_004CDC38_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x4];
    s32 unk20;
};

s32 func_004CDC38(struct func_004CDC38_arg0 *arg0) {
    s32 temp_s1;

    func_004FA860(arg0->unk20);
    temp_s1 = arg0->unk18 == 0;
    func_004FA840(arg0->unk20);
    return temp_s1;
}
