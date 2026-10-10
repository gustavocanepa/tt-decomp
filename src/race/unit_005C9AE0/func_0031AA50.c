#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0031AA50_temp_v0 {
    char pad0[0x188];
    f32 unk188;
};

void func_0031AA50(s32 arg0, f32 fparg0) {
    s32 var_v1;
    void **var_a0;
    struct func_0031AA50_temp_v0 *temp_v0;

    var_a0 = arg0 + 0x170;
    var_v1 = 5;
    do {
        temp_v0 = *var_a0;
        var_a0 += 0x6D;
        var_v1 -= 1;
        temp_v0->unk188 = fparg0;
    } while (var_v1 >= 0);
}
