#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550C08_arg0 {
    char pad0[0x32790];
    f32 unk32790;
};

s32 func_00550C08(struct func_00550C08_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk32790 < 0x1.0000000000000p+0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
