#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0036F6C8();                            /* extern */
s32 func_003CC770(s32);                         /* extern */

extern char D_005D3A10[];
struct func_00374350_arg0 {
    char pad0[0xDEC];
    s32 unkDEC;
    char padDF0[0x990];
    s32 unk1780;
};

s32 func_00374350(void *arg0) {
    func_0036F6C8();
    ((struct func_00374350_arg0 *)arg0)->unkDEC = (s32)D_005D3A10;
    func_003CC770(arg0 + 0xDF0);
    ((struct func_00374350_arg0 *)arg0)->unk1780 = 1;
}
