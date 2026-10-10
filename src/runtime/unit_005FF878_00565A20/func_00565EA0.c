#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565EA0_arg0 {
    char pad0[0x3F];
    u8 unk3F;
};

u8 func_00565EA0(struct func_00565EA0_arg0 *arg0) {
    return arg0->unk3F;
}
