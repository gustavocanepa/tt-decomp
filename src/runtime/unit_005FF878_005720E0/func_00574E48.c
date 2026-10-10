#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00574E48_arg0 {
    char pad0[0x16];
    u16 unk16;
};

u16 func_00574E48(struct func_00574E48_arg0 *arg0) {
    return arg0->unk16;
}
