#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005231A8_arg0 {
    char pad0[0x14];
    f32 unk14;
};

f32 func_005231A8(struct func_005231A8_arg0 *arg0) {
    return arg0->unk14;
}
