#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E5EA0(f32);                         /* extern */

struct func_002E5DF0_arg0_unk4 {
    char pad0[0x20A48];
    f32 unk20A48;
};
struct func_002E5DF0_arg0 {
    char pad0[0x4];
    struct func_002E5DF0_arg0_unk4 *unk4;
};

void func_002E5DF0(struct func_002E5DF0_arg0 *arg0) {
    func_002E5EA0(arg0->unk4->unk20A48);
}
