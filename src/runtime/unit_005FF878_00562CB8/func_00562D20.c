#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D20_arg0 {
    char pad0[0x1158];
    s32 unk1158;
};

void func_00562D20(struct func_00562D20_arg0 *arg0, s32 arg1) {
    arg0->unk1158 = arg1;
}
