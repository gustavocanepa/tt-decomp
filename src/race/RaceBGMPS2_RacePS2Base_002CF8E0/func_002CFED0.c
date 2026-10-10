#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002CFED0_arg0 {
    char pad0[0x1C0];
    f32 unk1C0;
};

f32 func_002CFED0(struct func_002CFED0_arg0 *arg0) {
    return arg0->unk1C0;
}
