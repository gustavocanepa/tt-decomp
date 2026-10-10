#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004181F0_arg0 {
    char pad0[0x168];
    f32 unk168;
};

void func_004181F0(struct func_004181F0_arg0 *arg0, f32 fparg0) {
    arg0->unk168 = fparg0;
}
