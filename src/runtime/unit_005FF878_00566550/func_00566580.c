#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00566580_arg0 {
    char pad0[0x54];
    f32 unk54;
};

void func_00566580(struct func_00566580_arg0 *arg0, f32 fparg0) {
    arg0->unk54 = fparg0;
}
