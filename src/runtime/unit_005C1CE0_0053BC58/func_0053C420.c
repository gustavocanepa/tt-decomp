#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053C420_arg0 {
    char pad0[0x19C];
    f32 unk19C;
};

void func_0053C420(struct func_0053C420_arg0 *arg0, f32 fparg0) {
    arg0->unk19C = fparg0;
}
