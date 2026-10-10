#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F8A38_arg0 {
    char pad0[0x5E2];
    u16 unk5E2;
};

u16 func_002F8A38(struct func_002F8A38_arg0 *arg0) {
    return arg0->unk5E2;
}
