#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C9F20();                            /* extern */
s32 func_004AE9C0(s32);                         /* extern */
s32 func_004F6678(void *, s32, s32);    /* extern */

extern char D_005DB220[];
struct func_004C2FD0_arg0 {
    s32 unk0;
    char pad4[0x30];
    s32 unk34;
    s32 unk38;
    char pad3C[0x2C];
    s32 unk68;
};

void func_004C2FD0(void *arg0, s32 arg1) {
    func_004C9F20();
    ((struct func_004C2FD0_arg0 *)arg0)->unk0 = (s32)D_005DB220;
    func_004AE9C0(arg0 + 4);
    ((struct func_004C2FD0_arg0 *)arg0)->unk34 = arg1;
    ((struct func_004C2FD0_arg0 *)arg0)->unk38 = 0;
    ((struct func_004C2FD0_arg0 *)arg0)->unk68 = 1;
    func_004F6678(arg0 + 0x3C, 0, 0x2C);
}
