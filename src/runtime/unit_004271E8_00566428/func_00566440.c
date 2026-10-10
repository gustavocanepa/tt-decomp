#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00566440_temp_v0 {
    char pad0[0x4];
    s32 unk4;
};

void *func_00566440(void **arg0) {
    void *temp_v0;

    temp_v0 = *arg0;
    return temp_v0 + (((struct func_00566440_temp_v0 *)temp_v0)->unk4 * 0x10) + 8;
}
