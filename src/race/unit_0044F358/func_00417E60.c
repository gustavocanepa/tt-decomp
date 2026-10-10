#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417E60_arg0 {
    char pad0[0x1EC];
    f32 unk1EC;
};

void func_00417E60(struct func_00417E60_arg0 *arg0, f32 fparg0) {
    arg0->unk1EC = fparg0;
}
