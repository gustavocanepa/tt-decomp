#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553648_arg0 {
    char pad0[0x2A4];
    f32 unk2A4;
};

void func_00553648(struct func_00553648_arg0 *arg0, f32 fparg0) {
    arg0->unk2A4 = fparg0;
}
