#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562888_arg0 {
    char pad0[0x10D4];
    s32 unk10D4;
};

void func_00562888(struct func_00562888_arg0 *arg0, s32 arg1) {
    arg0->unk10D4 = arg1;
}
