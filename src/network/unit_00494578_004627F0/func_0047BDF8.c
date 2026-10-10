#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047B0C0(s32 *, s32);              /* extern */
s32 func_0047C238(s32, s32);                /* extern */
s32 func_0050E1A8(s32 *);                       /* extern */

extern char D_005DA498[];
void func_0047BDF8(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_005DA498;
    func_0047C238(arg0 + 0x4, 2);
    func_0047B0C0(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
