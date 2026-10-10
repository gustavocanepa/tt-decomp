#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00535C40_arg0 {
    char pad0[0x74];
    s32 unk74;
};

void func_00535C40(struct func_00535C40_arg0 *arg0, s32 arg1) {
    arg0->unk74 = arg1;
}
