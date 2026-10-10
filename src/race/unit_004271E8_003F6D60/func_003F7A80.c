#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F7AC0(void *);                      /* extern */
s32 func_00400D68();                            /* extern */

extern char D_005D8B48[];
struct func_003F7A80_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_003F7A80(struct func_003F7A80_arg0 *arg0) {
    func_00400D68();
    arg0->unk8 = 0x20;
    arg0->unk0 = (s32)D_005D8B48;
    func_003F7AC0(arg0);
}
