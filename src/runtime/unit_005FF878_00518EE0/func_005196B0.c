#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005199C8(s32 *, s32);                  /* extern */

void func_005196B0(s32 *arg0, s32 arg1) {
    s32 *temp_a0;
    s32 *var_s0;
    s32 temp_a1;

    var_s0 = arg0;
    if (var_s0 != arg1) {
        do {
            temp_a1 = *var_s0;
            temp_a0 = var_s0;
            var_s0 += 1;
            func_005199C8(temp_a0, temp_a1);
        } while (var_s0 != arg1);
    }
}
