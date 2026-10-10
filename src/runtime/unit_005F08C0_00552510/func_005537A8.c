#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005537A8_arg0 {
    char pad0[0x1A8];
    s32 unk1A8;
};

void func_005537A8(struct func_005537A8_arg0 *arg0, s32 arg1) {
    arg0->unk1A8 = arg1;
}
