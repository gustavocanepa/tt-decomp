#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6880_arg0 {
    char pad0[0x684];
    f32 unk684;
};

f32 func_002E6880(struct func_002E6880_arg0 *arg0) {
    return arg0->unk684;
}
