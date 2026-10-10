#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00272978_arg0 {
    char pad0[0x8C];
    f32 unk8C;
};

void func_00272978(struct func_00272978_arg0 *arg0, f32 fparg0) {
    arg0->unk8C = fparg0;
}
