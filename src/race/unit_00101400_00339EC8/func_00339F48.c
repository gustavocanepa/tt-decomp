#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00339F48_arg0 {
    char pad0[0xD84];
    u32 unkD84;
    u32 unkD88;
    u32 unkD8C;
    s32 unkD90;
};

void func_00339F48(struct func_00339F48_arg0 *arg0, u32 arg1) {
    s32 var_v1;

    arg0->unkD84 = arg1;
    arg0->unkD8C = arg1;
    if (arg1 < 2U) {
        arg0->unkD88 = arg1;
    }
    arg0->unkD90 = 0;
    var_v1 = 0;
    if ((arg1 == 1) || (arg1 == 3)) {
        var_v1 = 1;
    }
    if (var_v1 != 0) {
        arg0->unkD90 = 1;
    }
}
