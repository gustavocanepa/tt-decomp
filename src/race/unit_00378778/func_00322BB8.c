#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00322BB8_arg0 {
    char pad0[0x2A8];
    s32 unk2A8;
};

void func_00322BB8(struct func_00322BB8_arg0 *arg0) {
    arg0->unk2A8 = 5;
}
