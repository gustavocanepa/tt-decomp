#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565BE0_arg0 {
    char pad0[0x4E];
    u8 unk4E;
};

u8 func_00565BE0(struct func_00565BE0_arg0 *arg0) {
    return arg0->unk4E;
}
