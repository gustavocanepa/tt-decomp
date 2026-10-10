#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546738_arg0 {
    char pad0[0x70];
    f32 unk70;
};

void func_00546738(struct func_00546738_arg0 *arg0, f32 fparg0) {
    arg0->unk70 = fparg0;
}
