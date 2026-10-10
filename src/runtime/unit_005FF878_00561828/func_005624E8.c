#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005624E8_arg0 {
    char pad0[0x11EC];
    s32 unk11EC;
};

void func_005624E8(struct func_005624E8_arg0 *arg0, s32 arg1) {
    arg0->unk11EC = arg1;
}
