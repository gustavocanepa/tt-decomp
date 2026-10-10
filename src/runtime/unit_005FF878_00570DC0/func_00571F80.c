#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00571F80_arg0 {
    char pad0[0x2C];
    s32 unk2C;
};

void func_00571F80(struct func_00571F80_arg0 *arg0, s32 arg1) {
    arg0->unk2C = arg1;
}
