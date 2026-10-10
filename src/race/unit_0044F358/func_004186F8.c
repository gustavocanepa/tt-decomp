#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004186F8_arg0 {
    char pad0[0x328];
    s32 unk328;
};

void func_004186F8(struct func_004186F8_arg0 *arg0, s32 arg1) {
    arg0->unk328 = arg1;
}
