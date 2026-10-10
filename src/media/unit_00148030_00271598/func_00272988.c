#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00272988_arg0 {
    char pad0[0x90];
    f32 unk90;
};

void func_00272988(struct func_00272988_arg0 *arg0, f32 fparg0) {
    arg0->unk90 = fparg0;
}
