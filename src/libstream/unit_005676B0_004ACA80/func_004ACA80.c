#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9C0(s32);                         /* extern */
s32 func_004AC758();                            /* extern */

extern char D_005DADF8[];
struct func_004ACA80_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_004ACA80(void *arg0) {
    func_004AC758();
    ((struct func_004ACA80_arg0 *)arg0)->unk8 = (s32)D_005DADF8;
    func_004AE9C0(arg0 + 0xC);
}
