#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553918_arg0 {
    char pad0[0x1D0];
    u8 unk1D0;
};

u8 func_00553918(struct func_00553918_arg0 *arg0) {
    return arg0->unk1D0;
}
