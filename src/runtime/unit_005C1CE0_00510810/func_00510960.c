#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00510960_temp_v0 {
    char pad0[0x4AC];
    s32 unk4AC;
};

void func_00510960(s32 arg0, s32 arg1) {
    struct func_00510960_temp_v0 *temp_v0;

    temp_v0 = *(void **)0x579774;
    if (temp_v0 != NULL) {
        temp_v0->unk4AC = arg1;
    }
}
