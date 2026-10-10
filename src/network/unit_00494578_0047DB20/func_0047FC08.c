#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047D860(void *, s32);             /* extern */
s32 func_004AE9F0(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA7A8[];
struct func_0047FC08_arg0 {
    char pad0[0x30];
    s32 unk30;
};

void func_0047FC08(void *arg0, s32 arg1) {
    ((struct func_0047FC08_arg0 *)arg0)->unk30 = (s32)D_005DA7A8;
    func_004AE9F0(arg0 + 0x1A50, 2);
    func_004AE9F0(arg0 + 0x1A20, 2);
    func_004AE9F0(arg0 + 0x19F0, 2);
    func_004AE9F0(arg0 + 0x19C0, 2);
    func_004AE9F0(arg0 + 0x1990, 2);
    func_004AE9F0(arg0 + 0x1960, 2);
    func_0047D860(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
