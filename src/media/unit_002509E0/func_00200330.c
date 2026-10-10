#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00200330_arg0 {
    char pad0[0x10C];
    s32 (*unk10C)();
};

void func_00200330(struct func_00200330_arg0 *arg0) {
    s32 (*temp_v0)();

    temp_v0 = arg0->unk10C;
    if (temp_v0 != NULL) {
        temp_v0();
    }
}
