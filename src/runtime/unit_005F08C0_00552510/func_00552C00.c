#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552C00_arg0 {
    char pad0[0xC0];
    f32 unkC0;
};

f32 func_00552C00(struct func_00552C00_arg0 *arg0) {
    return arg0->unkC0;
}
