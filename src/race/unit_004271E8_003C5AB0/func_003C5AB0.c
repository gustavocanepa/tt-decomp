/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_003C5AB0(s32 arg0) {
    s32 *var_a0;
    s32 var_v0;

    var_a0 = arg0 + 0x12C;
    var_v0 = 7;
    do {
        var_v0 -= 1;
        *var_a0 = 0;
        var_a0 -= 1;
    } while (var_v0 >= 0);
}
