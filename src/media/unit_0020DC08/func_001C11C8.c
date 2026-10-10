#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_001C11C8_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_001C11C8(struct func_001C11C8_arg0 *arg0) {
    arg0->unk20 = (s32) (arg0->unk20 + 1);
}
