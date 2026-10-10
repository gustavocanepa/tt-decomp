#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418268_arg0 {
    char pad0[0x32C];
    s32 unk32C;
};

void func_00418268(struct func_00418268_arg0 *arg0, s32 arg1) {
    arg0->unk32C = arg1;
}
