#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D7528_arg0 {
    char pad0[0x264];
    s32 unk264;
};

void func_001D7528(struct func_001D7528_arg0 *arg0, s32 arg1) {
    arg0->unk264 = arg1;
}
