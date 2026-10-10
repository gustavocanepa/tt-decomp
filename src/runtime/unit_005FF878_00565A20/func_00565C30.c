#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C30_arg0 {
    char pad0[0x54];
    u8 unk54;
};

u8 func_00565C30(struct func_00565C30_arg0 *arg0) {
    return arg0->unk54;
}
