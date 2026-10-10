#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0043E0B0(void *);                          /* extern */

struct func_0043E0F8_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_0043E0F8(struct func_0043E0F8_arg0 *arg0) {
    s32 var_v0;

    if (arg0->unk0 == 5) {
        return arg0->unk4;
    }
    var_v0 = 1;
    if (func_0043E0B0(arg0) == 0.0f) {
        var_v0 = 0;
    }
    return var_v0;
}
