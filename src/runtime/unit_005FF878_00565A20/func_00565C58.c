#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C58_arg0 {
    char pad0[0x5D];
    u8 unk5D;
};

u8 func_00565C58(struct func_00565C58_arg0 *arg0) {
    return arg0->unk5D;
}
