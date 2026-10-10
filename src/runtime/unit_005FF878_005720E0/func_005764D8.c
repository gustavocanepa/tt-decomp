#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005764D8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

s32 func_005764D8(struct func_005764D8_arg0 *arg0) {
    return arg0->unk1C;
}
