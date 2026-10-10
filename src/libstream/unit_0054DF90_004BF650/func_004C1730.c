#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9C0(s32);                         /* extern */
s32 func_004F6678(void *, s32, s32);    /* extern */

struct func_004C1730_arg0 {
    char pad0[0x5C];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
};

void func_004C1730(void *arg0) {
    func_004AE9C0(arg0 + 0x2200);
    func_004AE9C0(arg0 + 0x2230);
    ((struct func_004C1730_arg0 *)arg0)->unk5C = 0;
    ((struct func_004C1730_arg0 *)arg0)->unk60 = 0;
    ((struct func_004C1730_arg0 *)arg0)->unk64 = 0;
    ((struct func_004C1730_arg0 *)arg0)->unk68 = 0;
    func_004F6678(arg0 + 0x6C, 0, 0x38);
    func_004F6678(arg0 + 0xA4, 0, 0x38);
    func_004F6678(arg0 + 0x100, 0, 0x2000);
    func_004F6678(arg0 + 0x2100, 0, 0x100);
}
