#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0045F0A8_arg0 {
    char pad0[0x4C];
    f32 unk4C;
    char pad50[0x20];
    f32 unk70;
    char pad74[0x4];
    f32 unk78;
};

s32 func_0045F0A8(struct func_0045F0A8_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    s32 var_v0;

    var_v0 = 1;
    temp_f0 = arg0->unk4C + fparg0;
    arg0->unk4C = temp_f0;
    if (!(temp_f0 < (arg0->unk78 - arg0->unk70))) {
        var_v0 = 0;
    }
    return var_v0;
}
