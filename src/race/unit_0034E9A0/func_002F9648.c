#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F9648_arg0_unk10 {
    char pad0[0x32];
    u8 unk32;
};
struct func_002F9648_arg0 {
    char pad0[0x10];
    struct func_002F9648_arg0_unk10 *unk10;
    char pad14[0x7D4];
    f32 unk7E8;
};

f32 func_002F9648(struct func_002F9648_arg0 *arg0) {
    f32 var_f0;

    var_f0 = 0x0.0p+0f;
    if (arg0->unk10->unk32 == 3) {
        var_f0 = arg0->unk7E8;
    }
    return var_f0;
}
