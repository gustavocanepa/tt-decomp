#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectBase__sync();                            /* extern */
s32 func_004AE9F0(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005A4D50[];
struct func_00108908_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void func_00108908(struct func_00108908_arg0 *arg0, s32 arg1) {
    arg0->unk64 = (s32)D_005A4D50;
    GranTurismo4__GameObjectBase__sync();
    func_004AE9F0(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
