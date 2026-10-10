#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00555598_arg0 {
    char pad0[0x11E8];
    s32 unk11E8;
};

void func_00555598(struct func_00555598_arg0 *arg0, s32 arg1) {
    arg0->unk11E8 = arg1;
}
