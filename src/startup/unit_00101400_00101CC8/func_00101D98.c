#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00101E48(void *, s32);             /* extern */
s32 func_001094F0();                            /* extern */

extern char D_005A49D8[];
struct func_00101D98_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x40];
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
};

void func_00101D98(struct func_00101D98_arg0 *arg0) {
    func_001094F0();
    arg0->unkA8 = 0;
    arg0->unkAC = 0;
    arg0->unk64 = (s32)D_005A49D8;
    arg0->unkB0 = 0;
    func_00101E48(arg0, 0);
}
