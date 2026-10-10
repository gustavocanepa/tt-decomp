#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562948_arg0 {
    char pad0[0x1104];
    s32 unk1104;
};

void func_00562948(struct func_00562948_arg0 *arg0, s32 arg1) {
    arg0->unk1104 = arg1;
}
