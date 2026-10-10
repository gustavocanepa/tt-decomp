/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

struct func_0045BF58_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_0045BF58(void *arg0) {
    s32 *var_s0;
    s32 temp_v0;
    s32 var_s1;

    var_s0 = arg0 + 0x734;
    var_s1 = 2;
    do {
        temp_v0 = *var_s0;
        if (temp_v0 != 0) {
            func_004A45D0(temp_v0);
        }
        var_s1 -= 1;
        *var_s0 = 0;
        var_s0 += 1;
    } while (var_s1 >= 0);
    ((struct func_0045BF58_arg0 *)arg0)->unk8 = 0;
}
