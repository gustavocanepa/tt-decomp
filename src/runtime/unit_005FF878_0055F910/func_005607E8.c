#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005607E8_arg0 {
    char pad0[0x1204];
    s32 unk1204;
};

s32 func_005607E8(struct func_005607E8_arg0 *arg0) {
    return arg0->unk1204;
}
