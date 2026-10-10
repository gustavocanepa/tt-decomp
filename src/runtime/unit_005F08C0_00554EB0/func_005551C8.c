#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005551C8_arg0 {
    char pad0[0x3558];
    s32 unk3558;
};

s32 func_005551C8(struct func_005551C8_arg0 *arg0) {
    return arg0->unk3558;
}
