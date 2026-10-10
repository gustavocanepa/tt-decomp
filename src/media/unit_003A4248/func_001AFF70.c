#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AFF70_arg1 {
    char pad0[0x64];
    f32 unk64;
};

void func_001AFF70(f32 *arg0, struct func_001AFF70_arg1 *arg1) {
    *arg0 = arg1->unk64;
}
