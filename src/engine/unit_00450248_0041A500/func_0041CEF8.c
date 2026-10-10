#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00421B88(s32, s32);                /* extern */

struct func_0041CEF8_temp_a0 {
    char pad0[0x18];
    s32 unk18;
};

void func_0041CEF8(void **arg0) {
    s32 var_v0;
    struct func_0041CEF8_temp_a0 *temp_a0;

    temp_a0 = *arg0;
    var_v0 = 0;
    if (temp_a0 != NULL) {
        var_v0 = temp_a0->unk18;
    }
    func_00421B88(var_v0, 0);
}
