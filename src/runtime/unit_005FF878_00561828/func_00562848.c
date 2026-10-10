#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562848_arg0 {
    char pad0[0x10C4];
    s32 unk10C4;
};

void func_00562848(struct func_00562848_arg0 *arg0, s32 arg1) {
    arg0->unk10C4 = arg1;
}
