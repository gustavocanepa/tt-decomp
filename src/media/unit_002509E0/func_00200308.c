#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00200308_arg0 {
    char pad0[0x110];
    s32 (*unk110)(s32);
};

void func_00200308(struct func_00200308_arg0 *arg0, s32 arg1) {
    s32 (*temp_v0)(s32);

    temp_v0 = arg0->unk110;
    if (temp_v0 != NULL) {
        temp_v0(arg1);
    }
}
