#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052F200_arg0 {
    char pad0[0x10C];
    s32 unk10C;
};

void func_0052F200(struct func_0052F200_arg0 *arg0, s32 arg1) {
    arg0->unk10C = arg1;
}
