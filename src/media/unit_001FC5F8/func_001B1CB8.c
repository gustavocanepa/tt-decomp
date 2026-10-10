#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104838();                            /* extern */
s32 func_001071D0(s32);                         /* extern */
s32 Ipic__structor_0(void *);                      /* extern */
s32 func_004AE9C0(s32);                         /* extern */

struct func_001B1CB8_arg0 {
    char pad0[0xBC];
    s32 unkBC;
    char padC0[0x18];
    s32 unkD8;
    char padDC[0x8];
    s32 unkE4;
    char padE8[0x1C];
    s32 unk104;
    s32 unk108;
    s32 unk10C;
    s32 unk110;
};

void func_001B1CB8(void *arg0) {
    func_00104838();
    func_001071D0(arg0 + 0x40);
    func_004AE9C0(arg0 + 0x8C);
    ((struct func_001B1CB8_arg0 *)arg0)->unkBC = 0;
    ((struct func_001B1CB8_arg0 *)arg0)->unkD8 = 0;
    ((struct func_001B1CB8_arg0 *)arg0)->unkE4 = 0;
    Ipic__structor_0(arg0 + 0xE8);
    ((struct func_001B1CB8_arg0 *)arg0)->unk104 = 0;
    ((struct func_001B1CB8_arg0 *)arg0)->unk108 = 0;
    ((struct func_001B1CB8_arg0 *)arg0)->unk10C = 0;
    ((struct func_001B1CB8_arg0 *)arg0)->unk110 = 0;
}
