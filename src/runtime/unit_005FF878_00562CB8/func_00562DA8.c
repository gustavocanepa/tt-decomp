#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562DA8_arg0 {
    char pad0[0x117C];
    s32 unk117C;
};

s32 func_00562DA8(struct func_00562DA8_arg0 *arg0) {
    return arg0->unk117C;
}
