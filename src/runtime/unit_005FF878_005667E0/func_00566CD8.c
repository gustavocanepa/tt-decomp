#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00566CD8_arg0 {
    char pad0[0x4];
    f32 unk4;
};

void func_00566CD8(struct func_00566CD8_arg0 *arg0, f32 fparg0) {
    arg0->unk4 = fparg0;
}
