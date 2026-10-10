#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417D90_arg0 {
    char pad0[0x15C];
    f32 unk15C;
};

void func_00417D90(struct func_00417D90_arg0 *arg0, f32 fparg0) {
    arg0->unk15C = fparg0;
}
