#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417BF8_arg0 {
    char pad0[0xF8];
    f32 unkF8;
};

f32 func_00417BF8(struct func_00417BF8_arg0 *arg0) {
    return arg0->unkF8;
}
