#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562928_arg0 {
    char pad0[0x10FC];
    s32 unk10FC;
};

void func_00562928(struct func_00562928_arg0 *arg0, s32 arg1) {
    arg0->unk10FC = arg1;
}
