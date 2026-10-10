#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0037E280(s32, s32, void *);            /* extern */
s32 func_0037E2E0(s32, s32, s32);               /* extern */

struct func_0037F500_arg1_unk60 {
    char pad0[0x14];
    void *unk14;
};
struct func_0037F500_arg1 {
    char pad0[0x60];
    struct func_0037F500_arg1_unk60 *unk60;
};
struct func_0037F500_var_s0 {
    char pad0[0x10];
    void *unk10;
    s32 unk14;
};

void func_0037F500(s32 arg0, struct func_0037F500_arg1 *arg1) {
    s32 temp_a1;
    s32 var_s1;
    void *var_a2;
    struct func_0037F500_var_s0 *var_s0;

    var_s1 = 0;
    var_s0 = arg1->unk60->unk14;
    if (var_s0 != NULL) {
        var_a2 = var_s0;
        do {
            func_0037E280(arg0, var_s1, var_a2);
            temp_a1 = var_s1;
            func_0037E2E0(arg0, temp_a1, var_s0->unk14);
            var_s1 += 1;
            var_s0 = var_s0->unk10;
            var_a2 = var_s0;
        } while (var_s0 != NULL);
    }
}
