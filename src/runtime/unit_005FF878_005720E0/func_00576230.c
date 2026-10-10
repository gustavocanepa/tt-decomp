#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00576230_arg0 {
    char pad0[0x18];
    s16 unk18;
};

s16 func_00576230(struct func_00576230_arg0 *arg0, s16 arg1) {
    s16 temp_v0;

    temp_v0 = arg0->unk18;
    arg0->unk18 = arg1;
    return temp_v0;
}
