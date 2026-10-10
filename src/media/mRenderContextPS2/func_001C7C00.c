#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001C7C00_arg0 {
    char pad0[0x1D98];
    s32 unk1D98;
};

void func_001C7C00(struct func_001C7C00_arg0 *arg0) {
    arg0->unk1D98 = 1;
}
