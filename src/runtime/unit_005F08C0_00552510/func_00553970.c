#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553970_arg0 {
    char pad0[0x180];
    u8 unk180;
};

u8 func_00553970(struct func_00553970_arg0 *arg0) {
    return arg0->unk180;
}
