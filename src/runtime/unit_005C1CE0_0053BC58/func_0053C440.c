#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053C440_arg0 {
    char pad0[0x1A4];
    f32 unk1A4;
};

void func_0053C440(struct func_0053C440_arg0 *arg0, f32 fparg0) {
    arg0->unk1A4 = fparg0;
}
