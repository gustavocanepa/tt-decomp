#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC190_arg0 {
    char pad0[0xF0];
    f32 unkF0;
};

f32 func_001EC190(struct func_001EC190_arg0 *arg0) {
    return arg0->unkF0;
}
