#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002BCC80_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

s32 func_002BCC80(struct func_002BCC80_arg0 *arg0) {
    return arg0->unk10 * arg0->unk14;
}
