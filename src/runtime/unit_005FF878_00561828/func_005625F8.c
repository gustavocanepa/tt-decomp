#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005625F8_arg0 {
    char pad0[0x70];
    s32 unk70;
};

void func_005625F8(struct func_005625F8_arg0 *arg0, s32 arg1) {
    arg0->unk70 = arg1;
}
