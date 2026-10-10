#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004057A8_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};

void func_004057A8(struct func_004057A8_arg0 *arg0, s32 arg1) {
    arg0->unk4D8 = arg1;
}
