#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0017A550_arg0 {
    char pad0[0x180];
    s32 unk180;
    char pad184[0x158];
    s32 unk2DC;
};

s32 func_0017A550(struct func_0017A550_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0->unk180 != 0) {
        var_v1 = arg0->unk2DC != 0;
    }
    return var_v1;
}
