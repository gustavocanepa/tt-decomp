#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003C9628_arg0 {
    char pad0[0x80];
    s32 unk80;
};

s32 func_003C9628(struct func_003C9628_arg0 *arg0) {
    return arg0->unk80;
}
