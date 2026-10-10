#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00518D30_arg0 {
    char pad0[0x58];
    f32 unk58;
};

void func_00518D30(struct func_00518D30_arg0 *arg0, f32 fparg0) {
    arg0->unk58 = fparg0;
}
