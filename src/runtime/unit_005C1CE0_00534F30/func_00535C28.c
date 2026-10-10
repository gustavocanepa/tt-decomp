#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00535C28_arg0 {
    char pad0[0x70];
    s32 unk70;
};

s32 func_00535C28(struct func_00535C28_arg0 *arg0) {
    return arg0->unk70;
}
