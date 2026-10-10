#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004ADA50();                            /* extern */
s32 func_004F6678(s32, s32, s32);       /* extern */

struct func_00372AC8_arg0 {
    char pad0[0x68];
    s32 unk68;
};

void func_00372AC8(void *arg0) {
    func_004ADA50();
    ((struct func_00372AC8_arg0 *)arg0)->unk68 = 0;
    func_004F6678(arg0 + 0x58, 0, 0x10);
}
