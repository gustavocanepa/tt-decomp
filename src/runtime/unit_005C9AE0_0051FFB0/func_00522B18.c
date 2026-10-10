#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00522B18_arg0 {
    char pad0[0x894];
    s32 unk894;
};

void func_00522B18(struct func_00522B18_arg0 *arg0, s32 arg1) {
    arg0->unk894 = arg1;
}
