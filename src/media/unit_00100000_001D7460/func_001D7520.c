#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D7520_arg0 {
    char pad0[0x264];
    s32 unk264;
};

s32 func_001D7520(struct func_001D7520_arg0 *arg0) {
    return arg0->unk264;
}
