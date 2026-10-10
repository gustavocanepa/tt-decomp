#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004186D8_arg0 {
    char pad0[0x354];
    s32 unk354;
};

void func_004186D8(struct func_004186D8_arg0 *arg0, s32 arg1) {
    arg0->unk354 = arg1;
}
