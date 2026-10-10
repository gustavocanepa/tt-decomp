#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00206DF8(s32);                             /* extern */
s32 mWidget__setActive(s32, s32);                /* extern */
s32 func_0020D888();                                /* extern */

struct func_0027AAB0_arg0 {
    char pad0[0xBC];
    s32 unkBC;
};

void func_0027AAB0(struct func_0027AAB0_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 var_s0;
    s32 var_s1;

    if (func_0020D888() != 0) {
        var_s0 = arg0->unkBC;
        var_s1 = 0;
        if (var_s0 != 0) {
            do {
                if (var_s1 == arg1) {
                    mWidget__setActive(var_s0, 0);
                }
                if (var_s1 == arg2) {
                    mWidget__setActive(var_s0, 1);
                }
                var_s1 += 1;
                var_s0 = func_00206DF8(var_s0);
            } while (var_s0 != 0);
        }
    }
}
