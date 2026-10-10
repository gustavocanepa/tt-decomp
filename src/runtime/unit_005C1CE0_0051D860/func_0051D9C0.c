#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051D9C0_arg0 {
    char pad0[0x1F78];
    f32 unk1F78;
};

void func_0051D9C0(struct func_0051D9C0_arg0 *arg0, f32 fparg0) {
    arg0->unk1F78 = fparg0;
}
