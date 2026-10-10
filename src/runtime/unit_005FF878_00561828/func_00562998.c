#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562998_arg0 {
    char pad0[0x1118];
    s32 unk1118;
};

void func_00562998(struct func_00562998_arg0 *arg0, s32 arg1) {
    arg0->unk1118 = arg1;
}
