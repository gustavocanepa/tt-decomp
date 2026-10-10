#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FBBE0_arg0 {
    char pad0[0x8210];
    s32 unk8210;
};

void *func_003FBBE0(void *arg0) {
    s32 temp_v1;

    temp_v1 = ((struct func_003FBBE0_arg0 *)arg0)->unk8210;
    return arg0 + (((temp_v1 < 0) ? 0 : temp_v1) << 5) + 8;
}
