#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D7500_arg0 {
    char pad0[0x1DC];
    s32 unk1DC;
};

s32 func_001D7500(struct func_001D7500_arg0 *arg0) {
    return arg0->unk1DC;
}
