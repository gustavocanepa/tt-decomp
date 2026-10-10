#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0013C5B0_arg0 {
    char pad0[0x90];
    void *unk90;
};
struct func_0013C5B0_temp_v1 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_0013C5B0(struct func_0013C5B0_arg0 *arg0) {
    s32 var_v0;
    struct func_0013C5B0_temp_v1 *temp_v1;

    temp_v1 = arg0->unk90;
    var_v0 = 0;
    if (temp_v1 != NULL) {
        var_v0 = temp_v1->unk10 != 0;
    }
    return var_v0;
}
