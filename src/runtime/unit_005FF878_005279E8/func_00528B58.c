#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528B58_arg0 {
    char pad0[0x20];
    f32 unk20;
};

f32 func_00528B58(struct func_00528B58_arg0 *arg0) {
    return arg0->unk20;
}
