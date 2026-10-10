#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00523208_arg0 {
    char pad0[0x20];
    f32 unk20;
};

void func_00523208(struct func_00523208_arg0 *arg0, f32 fparg0) {
    arg0->unk20 = fparg0;
}
