#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418600_arg0 {
    char pad0[0xEC];
    f32 unkEC;
};

f32 func_00418600(struct func_00418600_arg0 *arg0) {
    return arg0->unkEC;
}
