#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D9D50_arg0 {
    char pad0[0x48];
    s32 unk48;
};

s32 func_001D9D50(struct func_001D9D50_arg0 *arg0) {
    return ((s32) arg0->unk48 >> 3) & 1;
}
