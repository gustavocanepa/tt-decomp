#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C60_arg0 {
    char pad0[0x5E];
    u8 unk5E;
};

u8 func_00565C60(struct func_00565C60_arg0 *arg0) {
    return arg0->unk5E;
}
