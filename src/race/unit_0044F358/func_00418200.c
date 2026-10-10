#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418200_arg0 {
    char pad0[0x2C4];
    f32 unk2C4;
};

void func_00418200(struct func_00418200_arg0 *arg0, f32 fparg0) {
    arg0->unk2C4 = fparg0;
}
