#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020DC50();                                /* extern */

struct func_0020E470_arg0_unk5C {
    char pad0[0x30];
    s32 unk30;
};
struct func_0020E470_arg0 {
    char pad0[0x5C];
    struct func_0020E470_arg0_unk5C *unk5C;
};

s32 func_0020E470(struct func_0020E470_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (func_0020DC50() != 0) {
        var_v0 = (arg0->unk5C->unk30 & 0xE00) != 0;
    }
    return var_v0;
}
