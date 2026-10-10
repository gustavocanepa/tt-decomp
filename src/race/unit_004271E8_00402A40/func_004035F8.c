#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00400CF0(s32);                         /* extern */
s32 func_00403378(s32);                             /* extern */

void func_004035F8(s32 arg0) {
    s32 temp_a0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s0 = arg0 + 4;
    var_s1 = 1;
    var_s2 = 0;
    do {
        temp_a0 = var_s0;
        var_s0 += 0xB8;
        var_s1 -= 1;
        var_s2 += func_00403378(temp_a0);
    } while (var_s1 >= 0);
    func_00400CF0(var_s2);
}
