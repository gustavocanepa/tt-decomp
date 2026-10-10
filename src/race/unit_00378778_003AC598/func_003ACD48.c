#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003ACD48_arg0 {
    char pad0[0x168];
    f32 unk168;
};

f32 func_003ACD48(struct func_003ACD48_arg0 *arg0) {
    return arg0->unk168;
}
