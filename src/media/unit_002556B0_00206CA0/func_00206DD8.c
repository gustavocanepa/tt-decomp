#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00206DD8_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

s32 func_00206DD8(struct func_00206DD8_arg0 *arg0) {
    return arg0->unk3C;
}
