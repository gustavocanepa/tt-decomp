#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562DB0_arg0 {
    char pad0[0x117C];
    s32 unk117C;
};

void func_00562DB0(struct func_00562DB0_arg0 *arg0, s32 arg1) {
    arg0->unk117C = arg1;
}
