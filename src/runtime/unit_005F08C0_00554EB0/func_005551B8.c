#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005551B8_arg0 {
    char pad0[0x3550];
    s32 unk3550;
};

s32 func_005551B8(struct func_005551B8_arg0 *arg0) {
    return arg0->unk3550;
}
