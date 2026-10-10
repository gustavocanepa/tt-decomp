#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003101B8_arg0_unk10 {
    char pad0[0x253];
    u8 unk253;
};
struct func_003101B8_arg0 {
    char pad0[0x10];
    struct func_003101B8_arg0_unk10 *unk10;
};

f32 func_003101B8(struct func_003101B8_arg0 *arg0) {
    f32 var_f0;
    u8 temp_a0;

    var_f0 = 0x1.05cca20000000p+9f;
    temp_a0 = arg0->unk10->unk253;
    if (temp_a0 != 3) {
        var_f0 = 0x1.d73d240000000p+8f;
        if (temp_a0 != 2) {
            var_f0 = 0x1.a2e1040000000p+8f;
        }
    }
    return var_f0;
}
