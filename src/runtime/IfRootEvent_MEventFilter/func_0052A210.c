#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052A210_arg0 {
    char pad0[0x6E0];
    s32 unk6E0;
};

void func_0052A210(struct func_0052A210_arg0 *arg0, s32 arg1) {
    arg0->unk6E0 = arg1;
}
