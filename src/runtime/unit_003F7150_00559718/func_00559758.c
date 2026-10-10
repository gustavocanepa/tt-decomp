#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559758_arg0 {
    char pad0[0x40];
    f32 unk40;
};

s32 func_00559758(struct func_00559758_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk40 > 0x0.0p+0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
