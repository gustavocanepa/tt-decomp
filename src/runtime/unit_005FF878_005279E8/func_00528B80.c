#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528B80_arg0 {
    char pad0[0x10];
    f32 unk10;
};

void func_00528B80(struct func_00528B80_arg0 *arg0, f32 fparg0) {
    arg0->unk10 = fparg0;
}
