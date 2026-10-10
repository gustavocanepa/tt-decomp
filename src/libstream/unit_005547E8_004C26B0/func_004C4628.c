#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C4200(s32);                         /* extern */

extern char D_0059C018[];
void func_004C4628(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_s0;
    s32 var_s1;

    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            var_s1 = 7;
            var_s0 = (s32)D_0059C018;
            var_a0 = (s32)D_0059C018;
            do {
                var_s0 += 0x18;
                var_s1 -= 1;
                func_004C4200(var_a0);
                var_a0 = var_s0;
            } while (var_s1 != -1);
        }
    }
}
