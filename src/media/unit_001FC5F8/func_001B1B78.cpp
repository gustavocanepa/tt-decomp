extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0057AA0C[];
struct func_001B1B78_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    char pad18[0xC];
    s32 unk24;
};

s32 func_001B1B78(char *arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_t0;

    temp_v1 = *(s32 *)D_0057AA0C;
    var_t0 = 0;
    temp_a1 = ((struct func_001B1B78_arg0 *)arg0)->unk10;
    temp_a0 = ((struct func_001B1B78_arg0 *)arg0)->unk24 ^ temp_v1;
    ((struct func_001B1B78_arg0 *)arg0)->unk24 = temp_v1;
    temp_v0 = (temp_v1 * 2) + (temp_a0 == 0);
    temp_v0_2 = (temp_v0 < 0) ? 0 : temp_v0;
    ((struct func_001B1B78_arg0 *)arg0)->unk14 = temp_v0_2;
    if (temp_v0_2 >= temp_a1) {
        ((struct func_001B1B78_arg0 *)arg0)->unk14 = (s32) (temp_a1 - 1);
        var_t0 = 1;
    }
    return var_t0;
}

}
