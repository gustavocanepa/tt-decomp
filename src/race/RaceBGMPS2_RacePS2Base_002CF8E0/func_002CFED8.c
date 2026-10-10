#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002CFED8_arg0 {
    char pad0[0x1C0];
    f32 unk1C0;
};

void func_002CFED8(struct func_002CFED8_arg0 *arg0, f32 fparg0) {
    arg0->unk1C0 = fparg0;
}
