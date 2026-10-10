#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_0041FFB0(u8 *arg0) {
    u8 temp_v0;
    void *var_a2;

    temp_v0 = *arg0;
    var_a2 = arg0 + 8;
    if (temp_v0 != 0xFF) {
        var_a2 = arg0 + (temp_v0 * 4) + 4;
    }
    return var_a2;
}
