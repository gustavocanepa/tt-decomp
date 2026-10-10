#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536C18_arg0 {
    char pad0[0xC8];
    f32 unkC8;
};

f32 func_00536C18(struct func_00536C18_arg0 *arg0) {
    return arg0->unkC8;
}
