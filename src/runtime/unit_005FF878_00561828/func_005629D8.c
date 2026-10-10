#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005629D8_arg0 {
    char pad0[0x1128];
    s32 unk1128;
};

void func_005629D8(struct func_005629D8_arg0 *arg0, s32 arg1) {
    arg0->unk1128 = arg1;
}
