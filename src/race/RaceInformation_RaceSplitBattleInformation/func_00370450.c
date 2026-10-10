#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00370450_arg0 {
    char pad0[0x124];
    s32 unk124;
};

s32 func_00370450(struct func_00370450_arg0 *arg0) {
    return arg0->unk124;
}
