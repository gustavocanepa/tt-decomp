#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00518CB8_arg0 {
    char pad0[0x64];
    f32 unk64;
};

f32 func_00518CB8(struct func_00518CB8_arg0 *arg0) {
    return arg0->unk64;
}
