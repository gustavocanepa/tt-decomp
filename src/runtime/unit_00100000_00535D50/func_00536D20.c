#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536D20_arg0 {
    char pad0[0xEC];
    f32 unkEC;
};

f32 func_00536D20(struct func_00536D20_arg0 *arg0) {
    return arg0->unkEC;
}
