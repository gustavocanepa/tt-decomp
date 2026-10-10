#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418638_arg0 {
    char pad0[0x334];
    s32 unk334;
};

void func_00418638(struct func_00418638_arg0 *arg0, s32 arg1) {
    arg0->unk334 = arg1;
}
