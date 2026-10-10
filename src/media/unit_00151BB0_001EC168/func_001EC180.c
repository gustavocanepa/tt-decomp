#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC180_arg0 {
    char pad0[0xE4];
    f32 unkE4;
    char padE8[0x4];
    f32 unkEC;
};

void func_001EC180(struct func_001EC180_arg0 *arg0, f32 fparg0) {
    arg0->unkE4 = fparg0;
    arg0->unkEC = fparg0;
}
