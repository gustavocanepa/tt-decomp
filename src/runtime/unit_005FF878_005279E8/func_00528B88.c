#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528B88_arg0 {
    char pad0[0x14];
    f32 unk14;
};

void func_00528B88(struct func_00528B88_arg0 *arg0, f32 fparg0) {
    arg0->unk14 = fparg0;
}
