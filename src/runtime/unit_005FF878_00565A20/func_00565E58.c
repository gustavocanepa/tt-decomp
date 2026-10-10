#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565E58_arg0 {
    char pad0[0x7F];
    u8 unk7F;
};

u8 func_00565E58(struct func_00565E58_arg0 *arg0) {
    return arg0->unk7F;
}
