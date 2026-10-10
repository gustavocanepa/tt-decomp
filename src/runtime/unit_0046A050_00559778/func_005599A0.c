#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005599A0_arg0 {
    char pad0[0x117C];
    s16 unk117C;
};

s16 func_005599A0(struct func_005599A0_arg0 *arg0) {
    return arg0->unk117C;
}
