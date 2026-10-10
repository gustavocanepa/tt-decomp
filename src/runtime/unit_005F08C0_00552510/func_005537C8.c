#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005537C8_arg0 {
    char pad0[0x19C];
    s32 unk19C;
};

s32 func_005537C8(struct func_005537C8_arg0 *arg0) {
    return arg0->unk19C;
}
