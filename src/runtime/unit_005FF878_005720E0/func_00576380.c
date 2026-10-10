#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00576380_arg0 {
    char pad0[0x1B];
    u8 unk1B;
};

u8 func_00576380(struct func_00576380_arg0 *arg0) {
    return arg0->unk1B;
}
