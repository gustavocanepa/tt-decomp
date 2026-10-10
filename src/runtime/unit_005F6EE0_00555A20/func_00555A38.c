#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00555A38_arg0 {
    char pad0[0xD0];
    f32 unkD0;
};

f32 func_00555A38(struct func_00555A38_arg0 *arg0) {
    return arg0->unkD0;
}
