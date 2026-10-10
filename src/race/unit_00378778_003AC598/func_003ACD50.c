#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003ACD50_arg0 {
    char pad0[0x16C];
    f32 unk16C;
};

f32 func_003ACD50(struct func_003ACD50_arg0 *arg0) {
    return arg0->unk16C;
}
