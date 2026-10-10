#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051CEC8_arg0 {
    char pad0[0x108];
    s32 unk108;
    s32 unk10C;
};

s32 func_0051CEC8(struct func_0051CEC8_arg0 *arg0) {
    return arg0->unk10C != arg0->unk108;
}
