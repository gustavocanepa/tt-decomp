#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C48_arg0 {
    char pad0[0x5B];
    u8 unk5B;
};

u8 func_00565C48(struct func_00565C48_arg0 *arg0) {
    return arg0->unk5B;
}
