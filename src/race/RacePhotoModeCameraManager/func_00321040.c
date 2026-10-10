#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00321040_arg0 {
    char pad0[0xF60];
    f32 unkF60;
};

f32 func_00321040(struct func_00321040_arg0 *arg0) {
    return arg0->unkF60;
}
