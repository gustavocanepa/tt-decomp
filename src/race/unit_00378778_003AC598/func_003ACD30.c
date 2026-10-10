#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003ACD30_arg0 {
    char pad0[0x15C];
    f32 unk15C;
};

f32 func_003ACD30(struct func_003ACD30_arg0 *arg0) {
    return arg0->unk15C;
}
