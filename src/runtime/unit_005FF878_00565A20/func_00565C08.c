#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C08_arg0 {
    char pad0[0x57];
    u8 unk57;
};

u8 func_00565C08(struct func_00565C08_arg0 *arg0) {
    return arg0->unk57;
}
