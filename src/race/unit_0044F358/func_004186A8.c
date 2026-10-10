#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004186A8_arg0 {
    char pad0[0x348];
    s32 unk348;
};

void func_004186A8(struct func_004186A8_arg0 *arg0, s32 arg1) {
    arg0->unk348 = arg1;
}
