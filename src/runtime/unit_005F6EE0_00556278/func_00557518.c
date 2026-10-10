#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00557518_arg0 {
    char pad0[0x1C];
    f32 unk1C;
};

void func_00557518(struct func_00557518_arg0 *arg0, f32 fparg0) {
    arg0->unk1C = fparg0;
}
