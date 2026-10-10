#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00540B00_arg0 {
    char pad0[0x18];
    f32 unk18;
};

void func_00540B00(struct func_00540B00_arg0 *arg0, f32 fparg0) {
    arg0->unk18 = fparg0;
}
