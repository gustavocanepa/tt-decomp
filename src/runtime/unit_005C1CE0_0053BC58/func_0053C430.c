#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053C430_arg0 {
    char pad0[0x1A0];
    f32 unk1A0;
};

void func_0053C430(struct func_0053C430_arg0 *arg0, f32 fparg0) {
    arg0->unk1A0 = fparg0;
}
