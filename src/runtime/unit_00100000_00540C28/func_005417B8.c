#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005417B8_arg0 {
    char pad0[0x118];
    f32 unk118;
};

void func_005417B8(struct func_005417B8_arg0 *arg0, f32 fparg0) {
    arg0->unk118 = fparg0;
}
