#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003CBBC8(s32);                         /* extern */

struct func_003CBC60_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x50];
    s32 unk5C;
    s32 unk60;
    char pad64[0xEC];
    s32 unk150;
};

void func_003CBC60(void *arg0) {
    s32 *var_s0;
    s32 var_v0;

    ((struct func_003CBC60_arg0 *)arg0)->unk5C = -1;
    ((struct func_003CBC60_arg0 *)arg0)->unk0 = 0;
    ((struct func_003CBC60_arg0 *)arg0)->unk4 = 0;
    ((struct func_003CBC60_arg0 *)arg0)->unk8 = 0;
    ((struct func_003CBC60_arg0 *)arg0)->unk60 = 0;
    func_003CBBC8(arg0 + 0x104);
    ((struct func_003CBC60_arg0 *)arg0)->unk150 = 0;
    var_v0 = 0x13;
    var_s0 = arg0 + 0x58;
    do {
        var_v0 -= 1;
        *var_s0 = 0;
        var_s0 -= 1;
    } while (var_v0 >= 0);
}
