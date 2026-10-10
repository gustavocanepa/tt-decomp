#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005231C0_arg0 {
    char pad0[0x20];
    f32 unk20;
};

f32 func_005231C0(struct func_005231C0_arg0 *arg0) {
    return arg0->unk20;
}
