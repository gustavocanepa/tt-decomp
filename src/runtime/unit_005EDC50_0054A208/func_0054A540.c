#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7590(s32, void *);                 /* extern */

s32 *func_0054A540(s32 *arg0, s32 arg1, s32 *arg2) {
    s32 *var_s0;
    s32 *var_s1;

    var_s1 = arg0;
    var_s0 = arg2;
    if (var_s1 != arg1) {
        do {
            if (var_s0 != NULL) {
                *var_s0 = *var_s1;
                func_002A7590(var_s0 + 1, var_s1 + 1);
            }
            var_s1 += 2;
            var_s0 += 2;
        } while (var_s1 != arg1);
    }
    return var_s0;
}
