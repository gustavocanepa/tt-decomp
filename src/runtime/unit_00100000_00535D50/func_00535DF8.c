#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00535DF8_arg0 {
    char pad0[0x28];
    f32 unk28;
};

void func_00535DF8(struct func_00535DF8_arg0 *arg0, f32 fparg0) {
    arg0->unk28 = fparg0;
}
