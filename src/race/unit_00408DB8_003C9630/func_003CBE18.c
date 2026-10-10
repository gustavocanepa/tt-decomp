#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003E5988(s32);                             /* extern */
void *func_0041FDA0(s32, s32);                      /* extern */

struct func_003CBE18_temp_v0 {
    char pad0[0x40];
    u32 unk40;
};

struct func_003CBE18_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_003CBE18(void *arg0) {
    s32 temp_a0;
    s32 var_s1;
    void **var_s0;
    struct func_003CBE18_temp_v0 *temp_v0;

    var_s0 = arg0 + 0xC;
    var_s1 = 0;
    do {
        temp_a0 = var_s1;
        var_s1 += 1;
        temp_v0 = func_0041FDA0(((struct func_003CBE18_arg0 *)arg0)->unk4, func_003E5988(temp_a0));
        *var_s0 = temp_v0;
        if ((temp_v0 != NULL) && ((u32) temp_v0->unk40 >= 0x14U)) {
            *var_s0 = NULL;
        }
        var_s0 += 1;
    } while (var_s1 < 0x14);
}
