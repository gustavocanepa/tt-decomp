#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565E70_arg0 {
    char pad0[0x87];
    u8 unk87;
};

u8 func_00565E70(struct func_00565E70_arg0 *arg0) {
    return arg0->unk87;
}
