#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00263CD8_arg0 {
    char pad0[0x8C];
    s32 unk8C;
};

void func_00263CD8(struct func_00263CD8_arg0 *arg0) {
    arg0->unk8C = (s32) (arg0->unk8C ^ 1);
}
