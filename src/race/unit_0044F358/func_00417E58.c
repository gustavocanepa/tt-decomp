#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417E58_arg0 {
    char pad0[0x1EC];
    f32 unk1EC;
};

f32 func_00417E58(struct func_00417E58_arg0 *arg0) {
    return arg0->unk1EC;
}
