#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00522D90_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

s32 func_00522D90(struct func_00522D90_arg0 *arg0) {
    return arg0->unk1C;
}
