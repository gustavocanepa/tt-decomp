#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005231E8_arg0 {
    char pad0[0x10];
    f32 unk10;
};

void func_005231E8(struct func_005231E8_arg0 *arg0, f32 fparg0) {
    arg0->unk10 = fparg0;
}
