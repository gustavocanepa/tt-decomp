#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00520810_arg0 {
    char pad0[0x4A];
    u16 unk4A;
};

u16 func_00520810(struct func_00520810_arg0 *arg0) {
    return arg0->unk4A;
}
