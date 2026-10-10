#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005125F8_arg0 {
    char pad0[0x300];
    s32 unk300;
};

void func_005125F8(struct func_005125F8_arg0 *arg0, s32 arg1) {
    arg0->unk300 = arg1;
}
