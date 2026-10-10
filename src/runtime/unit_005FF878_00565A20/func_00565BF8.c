#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565BF8_arg0 {
    char pad0[0x51];
    u8 unk51;
};

u8 func_00565BF8(struct func_00565BF8_arg0 *arg0) {
    return arg0->unk51;
}
