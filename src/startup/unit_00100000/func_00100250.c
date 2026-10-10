#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00100928();                            /* extern */
s32 func_004AE9C0(s32);                         /* extern */

extern char D_005A4860[];
struct func_00100250_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x34];
    s32 unk9C;
};

void func_00100250(void *arg0) {
    func_00100928();
    ((struct func_00100250_arg0 *)arg0)->unk64 = (s32)D_005A4860;
    func_004AE9C0(arg0 + 0x6C);
    ((struct func_00100250_arg0 *)arg0)->unk9C = 0;
}
