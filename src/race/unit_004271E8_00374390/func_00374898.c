#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0036FCF8();                            /* extern */
void func_003CCE48(s32);                         /* extern */

struct func_00374898_arg0 {
    char pad0[0x1780];
    s32 unk1780;
};

void func_00374898(void *arg0) {
    func_0036FCF8();
    func_003CCE48(arg0 + 0xDF0);
    ((struct func_00374898_arg0 *)arg0)->unk1780 = 1;
}
