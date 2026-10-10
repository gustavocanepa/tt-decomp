#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528BA8_arg0 {
    char pad0[0x24];
    f32 unk24;
};

void func_00528BA8(struct func_00528BA8_arg0 *arg0, f32 fparg0) {
    arg0->unk24 = fparg0;
}
