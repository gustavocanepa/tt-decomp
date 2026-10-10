#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552C08_arg0 {
    char pad0[0xC4];
    f32 unkC4;
};

f32 func_00552C08(struct func_00552C08_arg0 *arg0) {
    return arg0->unkC4;
}
