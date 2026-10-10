#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542020_arg0 {
    char pad0[0x6C];
    f32 unk6C;
};

void func_00542020(struct func_00542020_arg0 *arg0, f32 fparg0) {
    arg0->unk6C = fparg0;
}
