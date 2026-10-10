#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00426F80_arg0 {
    char pad0[0x440];
    s32 unk440;
};

s32 func_00426F80(struct func_00426F80_arg0 *arg0) {
    return arg0->unk440;
}
