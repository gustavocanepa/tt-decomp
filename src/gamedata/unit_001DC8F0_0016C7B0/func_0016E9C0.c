#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7618();                            /* extern */
s32 func_003818D0(s32, s32, s32);       /* extern */

extern char D_005A89D0[];
struct func_0016E9C0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_0016E9C0(void *arg0) {
    func_002A7618();
    ((struct func_0016E9C0_arg0 *)arg0)->unk4 = (s32)D_005A89D0;
    func_003818D0(arg0 + 0x10, 1, 0xAF);
}
