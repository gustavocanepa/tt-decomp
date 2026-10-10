#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004447B8_arg0 {
    char pad0[0x40];
    f32 unk40;
};

void func_004447B8(struct func_004447B8_arg0 *arg0, f32 fparg0) {
    arg0->unk40 = fparg0;
}
