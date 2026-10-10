#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00540AE8_arg0 {
    char pad0[0x14];
    f32 unk14;
};

f32 func_00540AE8(struct func_00540AE8_arg0 *arg0) {
    return arg0->unk14;
}
