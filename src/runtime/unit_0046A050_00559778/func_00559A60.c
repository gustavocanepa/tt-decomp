#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A60_arg0 {
    char pad0[0x1178];
    s32 unk1178;
};

void func_00559A60(struct func_00559A60_arg0 *arg0, s32 arg1) {
    arg0->unk1178 = arg1;
}
