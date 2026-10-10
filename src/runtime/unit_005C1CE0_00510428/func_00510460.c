#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00510460_temp_v0 {
    char pad0[0x47C];
    s32 unk47C;
};

void func_00510460(s32 arg0, s32 arg1) {
    struct func_00510460_temp_v0 *temp_v0;

    temp_v0 = *(void **)0x579774;
    if (temp_v0 != NULL) {
        temp_v0->unk47C = arg1;
    }
}
