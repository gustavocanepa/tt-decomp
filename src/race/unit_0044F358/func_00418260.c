#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418260_arg0 {
    char pad0[0x2DC];
    f32 unk2DC;
};

void func_00418260(struct func_00418260_arg0 *arg0, f32 fparg0) {
    arg0->unk2DC = fparg0;
}
