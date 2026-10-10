#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004134B0(s32);                         /* extern */
s32 func_004F6678(void *, s32, s32);    /* extern */

struct func_00413520_arg0 {
    s32 unk0;
    char pad4[0x18];
    s32 unk1C;
};

void func_00413520(void *arg0, s32 arg1) {
    ((struct func_00413520_arg0 *)arg0)->unk0 = arg1;
    func_004134B0(arg0 + 4);
    ((struct func_00413520_arg0 *)arg0)->unk1C = 0;
    func_004F6678(arg0 + 0x14, 0, 8);
}
