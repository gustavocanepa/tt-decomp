#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004186E8_arg0 {
    char pad0[0x324];
    s32 unk324;
};

void func_004186E8(struct func_004186E8_arg0 *arg0, s32 arg1) {
    arg0->unk324 = arg1;
}
