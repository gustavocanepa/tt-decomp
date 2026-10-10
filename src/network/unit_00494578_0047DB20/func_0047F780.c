#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047E9C0(void *, s32);             /* extern */
s32 func_0047F028(void *, s32);             /* extern */
s32 func_0047F880();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA748[];
struct func_0047F780_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_0047F780(void *arg0, s32 arg1) {
    ((struct func_0047F780_arg0 *)arg0)->unk20 = (s32)D_005DA748;
    func_0047F880();
    func_0047E9C0(arg0 + 0x24, 2);
    func_0047F028(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
