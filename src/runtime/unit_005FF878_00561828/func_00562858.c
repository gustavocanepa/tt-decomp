#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562858_arg0 {
    char pad0[0x10C8];
    s32 unk10C8;
};

void func_00562858(struct func_00562858_arg0 *arg0, s32 arg1) {
    arg0->unk10C8 = arg1;
}
