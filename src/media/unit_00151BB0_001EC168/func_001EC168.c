#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC168_arg0 {
    char pad0[0xE0];
    f32 unkE0;
    char padE4[0x4];
    f32 unkE8;
};

void func_001EC168(struct func_001EC168_arg0 *arg0, f32 fparg0) {
    arg0->unkE0 = fparg0;
    arg0->unkE8 = fparg0;
}
