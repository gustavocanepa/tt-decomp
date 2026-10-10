#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556260_arg0 {
    char pad0[0x37];
    u8 unk37;
};

u8 func_00556260(struct func_00556260_arg0 *arg0) {
    return arg0->unk37;
}
