#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC178_arg0 {
    char pad0[0xE4];
    f32 unkE4;
};

f32 func_001EC178(struct func_001EC178_arg0 *arg0) {
    return arg0->unkE4;
}
