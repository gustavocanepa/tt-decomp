#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00561C78_arg0 {
    char pad0[0xB18];
    s32 unkB18;
};

s32 func_00561C78(struct func_00561C78_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkB18;
    arg0->unkB18 = 0;
    return temp_v0;
}
