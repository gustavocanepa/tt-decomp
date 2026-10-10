#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FBE48(void *, s32);                 /* extern */

struct func_003FBC88_arg0 {
    char pad0[0x8210];
    s32 unk8210;
};

void func_003FBC88(struct func_003FBC88_arg0 *arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        if (var_s0 != arg0->unk8210) {
            func_003FBE48(arg0, var_s0);
        }
        var_s0 += 1;
    } while (var_s0 < 0x3E8);
}
