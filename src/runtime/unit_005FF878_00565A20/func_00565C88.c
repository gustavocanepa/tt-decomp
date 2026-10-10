#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C88_arg0 {
    char pad0[0x63];
    u8 unk63;
};

u8 func_00565C88(struct func_00565C88_arg0 *arg0) {
    return arg0->unk63;
}
