#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004252A8_arg0 {
    char pad0[0x78];
    f32 unk78;
};

f32 func_004252A8(struct func_004252A8_arg0 *arg0) {
    return arg0->unk78;
}
