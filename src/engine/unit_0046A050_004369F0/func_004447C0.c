#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004447C0_arg0 {
    char pad0[0x40];
    f32 unk40;
};

f32 func_004447C0(struct func_004447C0_arg0 *arg0) {
    return arg0->unk40;
}
