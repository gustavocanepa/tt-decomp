#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E68D8_arg0 {
    char pad0[0x74F];
    u8 unk74F;
};

u8 func_002E68D8(struct func_002E68D8_arg0 *arg0) {
    return arg0->unk74F;
}
