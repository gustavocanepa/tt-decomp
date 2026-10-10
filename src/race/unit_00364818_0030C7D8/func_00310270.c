#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00310270_arg0_unk10 {
    char pad0[0x253];
    u8 unk253;
};
struct func_00310270_arg0 {
    char pad0[0x10];
    struct func_00310270_arg0_unk10 *unk10;
};

f32 func_00310270(struct func_00310270_arg0 *arg0) {
    f32 var_f0;

    var_f0 = 0x1.f400000000000p+8f;
    if (arg0->unk10->unk253 != 3) {
        var_f0 = 0x1.1200000000000p+8f;
    }
    return var_f0;
}
