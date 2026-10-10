#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005108C0_temp_v0 {
    char pad0[0x4B8];
    s32 unk4B8;
};

void func_005108C0(s32 arg0, s32 arg1) {
    struct func_005108C0_temp_v0 *temp_v0;

    temp_v0 = *(void **)0x579774;
    if (temp_v0 != NULL) {
        temp_v0->unk4B8 = arg1;
    }
}
