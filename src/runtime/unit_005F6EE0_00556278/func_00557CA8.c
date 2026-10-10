#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00557CA8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

void func_00557CA8(struct func_00557CA8_arg0 *arg0, s32 arg1) {
    arg0->unk1C = arg1;
}
