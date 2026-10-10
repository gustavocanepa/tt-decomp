#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D74D0_arg0 {
    char pad0[0x50];
    s32 unk50;
};

s32 func_001D74D0(struct func_001D74D0_arg0 *arg0) {
    return arg0->unk50;
}
