#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003ACD18_arg0 {
    char pad0[0x150];
    f32 unk150;
};

f32 func_003ACD18(struct func_003ACD18_arg0 *arg0) {
    return arg0->unk150;
}
