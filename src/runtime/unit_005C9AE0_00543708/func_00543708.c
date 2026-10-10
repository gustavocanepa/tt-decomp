#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9C0(s32);                         /* extern */
s32 func_00543900();                            /* extern */

extern char D_005BE0F8[];
struct func_00543708_arg0 {
    char pad0[0x10C];
    s32 unk10C;
};

void func_00543708(void *arg0) {
    func_00543900();
    ((struct func_00543708_arg0 *)arg0)->unk10C = (s32)D_005BE0F8;
    func_004AE9C0(arg0 + 0x110);
}
