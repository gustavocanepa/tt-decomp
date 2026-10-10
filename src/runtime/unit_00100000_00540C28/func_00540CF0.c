#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00540CF0_arg0 {
    char pad0[0x30];
    f32 unk30;
};

void func_00540CF0(struct func_00540CF0_arg0 *arg0, f32 fparg0) {
    arg0->unk30 = fparg0;
}
