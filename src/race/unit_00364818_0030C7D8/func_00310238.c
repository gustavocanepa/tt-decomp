#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00310238_arg0_unk10 {
    char pad0[0x253];
    u8 unk253;
};
struct func_00310238_arg0 {
    char pad0[0x10];
    struct func_00310238_arg0_unk10 *unk10;
};

f32 func_00310238(struct func_00310238_arg0 *arg0) {
    f32 var_f0;

    var_f0 = -0x1.05cca20000000p+10f;
    if (arg0->unk10->unk253 != 3) {
        var_f0 = -0x1.5456d20000000p+9f;
    }
    return var_f0;
}
