#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00100928();                            /* extern */
s32 func_001DD8F0(s32);                         /* extern */
s32 func_004AE9C0(void *);                      /* extern */

extern char D_005A4DE0[];
struct func_00108CA8_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    s32 unk70;
};

void func_00108CA8(void *arg0) {
    func_00100928();
    ((struct func_00108CA8_arg0 *)arg0)->unk64 = (s32)D_005A4DE0;
    func_001DD8F0(arg0 + 0x6C);
    ((struct func_00108CA8_arg0 *)arg0)->unk70 = 0;
    func_004AE9C0(arg0 + 0x74);
}
