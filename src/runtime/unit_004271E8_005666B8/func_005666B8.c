/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_005666B8(s32 arg0) {
    s32 *var_a0;
    s32 var_v0;

    var_a0 = arg0 + 0x31C;
    var_v0 = 199;
    do {
        var_v0 -= 1;
        *var_a0 = 0;
        var_a0 -= 1;
    } while (var_v0 >= 0);
}
