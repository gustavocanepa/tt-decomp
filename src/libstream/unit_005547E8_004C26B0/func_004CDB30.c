#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA840(s32);                         /* extern */
s32 func_004FA860(s32);                         /* extern */

struct func_004CDB30_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad1C[0x4];
    s32 unk20;
};

void func_004CDB30(struct func_004CDB30_arg0 *arg0) {
    func_004FA860(arg0->unk20);
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    func_004FA840(arg0->unk20);
}
