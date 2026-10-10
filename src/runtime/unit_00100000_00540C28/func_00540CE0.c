#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00540CE0_arg0 {
    char pad0[0x2C];
    f32 unk2C;
};

void func_00540CE0(struct func_00540CE0_arg0 *arg0, f32 fparg0) {
    arg0->unk2C = fparg0;
}
