#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004605F8(s32, u8);                         /* extern */

struct func_0045EA18_arg0 {
    char pad0[0x2C];
    void *unk2C;
    s32 unk30;
};
struct func_0045EA18_temp_v0 {
    char pad0[0x16];
    u8 unk16;
};

void func_0045EA18(struct func_0045EA18_arg0 *arg0, s32 arg1) {
    u8 var_a1;
    struct func_0045EA18_temp_v0 *temp_v0;

    if (arg1 != 0) {
        temp_v0 = arg0->unk2C;
        var_a1 = 0;
        if (temp_v0 != NULL) {
            var_a1 = temp_v0->unk16;
        }
        arg0->unk30 = func_004605F8(arg1, var_a1);
    }
}
