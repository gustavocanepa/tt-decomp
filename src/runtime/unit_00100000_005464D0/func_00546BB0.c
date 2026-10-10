#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546BB0_arg0 {
    char pad0[0x10C];
    s32 unk10C;
};

void func_00546BB0(struct func_00546BB0_arg0 *arg0, s32 arg1) {
    arg0->unk10C = arg1;
}
