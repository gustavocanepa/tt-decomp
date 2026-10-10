#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0017A570_arg0 {
    char pad0[0x1D0];
    s32 unk1D0;
    char pad1D4[0x95C];
    s32 unkB30;
};

s32 func_0017A570(struct func_0017A570_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0->unk1D0 != 0) {
        var_v1 = arg0->unkB30 != 0;
    }
    return var_v1;
}
