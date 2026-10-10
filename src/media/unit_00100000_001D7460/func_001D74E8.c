#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D74E8_arg0 {
    char pad0[0x114];
    s32 unk114;
};

void func_001D74E8(struct func_001D74E8_arg0 *arg0, s32 arg1) {
    arg0->unk114 = arg1;
}
