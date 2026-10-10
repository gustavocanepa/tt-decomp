#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562808_arg0 {
    char pad0[0x10B4];
    s32 unk10B4;
};

void func_00562808(struct func_00562808_arg0 *arg0, s32 arg1) {
    arg0->unk10B4 = arg1;
}
