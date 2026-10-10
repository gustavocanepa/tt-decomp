#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055E068_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0055E068(struct func_0055E068_arg0 *arg0, s32 arg1) {
    arg0->unk10 = arg1;
}
