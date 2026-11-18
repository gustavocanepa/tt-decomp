#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0020DC50();                                /* extern */

struct func_0020E3C0_arg0_unk5C {
    char pad0[0x30];
    u32 unk30;
};
struct func_0020E3C0_arg0 {
    char pad0[0x5C];
    struct func_0020E3C0_arg0_unk5C *unk5C;
};

s32 func_0020E3C0(struct func_0020E3C0_arg0 *arg0) {
    s32 var_v0;

    if (func_0020DC50() != 0) {
        var_v0 = M2C_FIELD(arg0->unk5C, u32 *, 0x30) >> 9;
        var_v0 = var_v0 & 7;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
