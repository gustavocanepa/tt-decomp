#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B92F8(void *, s32, s32);            /* extern */
s32 func_00206DF8(s32);                             /* extern */

struct func_001B9390_arg0 {
    char pad0[0xBC];
    s32 unkBC;
};

void func_001B9390(struct func_001B9390_arg0 *arg0, s32 arg1) {
    s32 var_a2;
    s32 var_s0;

    var_s0 = arg0->unkBC;
    if (var_s0 != 0) {
        var_a2 = var_s0;
        do {
            func_001B92F8(arg0, arg1, var_a2);
            var_s0 = func_00206DF8(var_s0);
            var_a2 = var_s0;
        } while (var_s0 != 0);
    }
}
