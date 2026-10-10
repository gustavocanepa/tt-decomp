#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00564C10_arg0 {
    char pad0[0x88];
    s32 unk88;
};

void func_00564C10(struct func_00564C10_arg0 *arg0, s32 arg1) {
    arg0->unk88 = arg1;
}
