#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528B60_arg0 {
    char pad0[0x24];
    f32 unk24;
};

f32 func_00528B60(struct func_00528B60_arg0 *arg0) {
    return arg0->unk24;
}
