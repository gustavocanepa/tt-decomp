#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00338D48_var_a0 {
    s128 unk0;
    char pad10[0xB0];
    s128 unkC0;
};

void func_00338D48(void *arg0) {
    s32 var_v1;
    void *var_a0;

    var_a0 = arg0;
    var_v1 = 0xB;
    do {
        var_v1 -= 1;
        ((struct func_00338D48_var_a0 *)var_a0)->unk0 = (s128) ((struct func_00338D48_var_a0 *)var_a0)->unkC0;
        var_a0 += 0x10;
    } while (var_v1 >= 0);
}
