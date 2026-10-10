#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418210_arg0 {
    char pad0[0x2C8];
    f32 unk2C8;
};

void func_00418210(struct func_00418210_arg0 *arg0, f32 fparg0) {
    arg0->unk2C8 = fparg0;
}
