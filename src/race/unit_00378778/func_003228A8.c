#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003228A8_arg0 {
    char pad0[0x1C8];
    s32 unk1C8;
};

void func_003228A8(struct func_003228A8_arg0 *arg0, s32 arg1) {
    arg0->unk1C8 = arg1;
}
