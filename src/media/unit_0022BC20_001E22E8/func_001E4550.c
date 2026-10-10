#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E4550_arg0 {
    char pad0[0x6D8];
    s32 unk6D8;
};

s32 func_001E4550(struct func_001E4550_arg0 *arg0) {
    return arg0->unk6D8;
}
