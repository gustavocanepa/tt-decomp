#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004209C8(void *, s32, s32);        /* extern */
s32 func_00421BF0(s32);                     /* extern */

struct func_0039E5D8_arg0 {
    char pad0[0x87C];
    s32 unk87C;
    char pad880[0x4];
    void *unk884;
};
struct func_0039E5D8_temp_a0 {
    char pad0[0x7C];
    s32 unk7C;
};

s32 func_0039E5D8(struct func_0039E5D8_arg0 *arg0) {
    struct func_0039E5D8_temp_a0 *temp_a0;

    if ((arg0->unk884 != NULL) && (arg0->unk87C > 0)) {
        func_00421BF0(1);
        temp_a0 = arg0->unk884;
        func_004209C8(temp_a0, 0, temp_a0->unk7C);
    }
}
