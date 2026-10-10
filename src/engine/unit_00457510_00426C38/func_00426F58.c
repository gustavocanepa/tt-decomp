#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00426F58_arg0 {
    char pad0[0x440];
    s32 unk440;
    s32 unk444;
};

s32 func_00426F58(struct func_00426F58_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unk440 != 0) || (arg0->unk444 != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}
