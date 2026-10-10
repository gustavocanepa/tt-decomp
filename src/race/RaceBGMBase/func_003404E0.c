#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003404E0_arg0 {
    char pad0[0x4];
    void *unk4;
};
struct func_003404E0_temp_v1 {
    char pad0[0x60];
    s32 unk60;
};

s32 func_003404E0(struct func_003404E0_arg0 *arg0) {
    s32 var_v0;
    struct func_003404E0_temp_v1 *temp_v1;

    temp_v1 = arg0->unk4;
    var_v0 = 0;
    if (temp_v1 != NULL) {
        var_v0 = temp_v1->unk60;
    }
    return var_v0;
}
