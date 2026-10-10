#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562878_arg0 {
    char pad0[0x10D0];
    s32 unk10D0;
};

void func_00562878(struct func_00562878_arg0 *arg0, s32 arg1) {
    arg0->unk10D0 = arg1;
}
