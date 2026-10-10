#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542758_arg0 {
    char pad0[0x60];
    f32 unk60;
};

void func_00542758(struct func_00542758_arg0 *arg0, f32 fparg0) {
    arg0->unk60 = fparg0;
}
