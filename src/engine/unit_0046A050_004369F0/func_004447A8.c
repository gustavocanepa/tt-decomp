#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004447A8_arg0 {
    char pad0[0x3C];
    f32 unk3C;
};

void func_004447A8(struct func_004447A8_arg0 *arg0, f32 fparg0) {
    arg0->unk3C = fparg0;
}
