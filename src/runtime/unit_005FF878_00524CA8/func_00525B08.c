#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00524D68(s32, s32);                    /* extern */

void func_00525B08(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_s0;

    var_s0 = arg0;
    if (var_s0 != arg1) {
        do {
            if (var_s0 != arg2) {
                func_00524D68(var_s0, arg2);
            }
            var_s0 += 0x10;
        } while (var_s0 != arg1);
    }
}
