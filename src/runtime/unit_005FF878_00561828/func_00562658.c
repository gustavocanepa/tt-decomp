#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562658_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

void func_00562658(struct func_00562658_arg0 *arg0, s32 arg1) {
    arg0->unk7C = arg1;
}
