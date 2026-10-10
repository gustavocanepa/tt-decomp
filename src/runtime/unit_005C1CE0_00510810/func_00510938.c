#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00510938_temp_v0 {
    char pad0[0x4BC];
    s32 unk4BC;
};

void func_00510938(s32 arg0, s32 arg1) {
    struct func_00510938_temp_v0 *temp_v0;

    temp_v0 = *(void **)0x579774;
    if (temp_v0 != NULL) {
        temp_v0->unk4BC = arg1;
    }
}
