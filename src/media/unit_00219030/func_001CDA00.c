#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001CDA00_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_001CDA00(struct func_001CDA00_arg0 *arg0, s32 arg1) {
    arg0->unk14 = arg1;
}
