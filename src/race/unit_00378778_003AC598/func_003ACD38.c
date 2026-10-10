#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003ACD38_arg0 {
    char pad0[0x160];
    f32 unk160;
};

f32 func_003ACD38(struct func_003ACD38_arg0 *arg0) {
    return arg0->unk160;
}
