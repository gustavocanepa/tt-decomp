#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D90_arg0 {
    char pad0[0x1174];
    s32 unk1174;
};

void func_00562D90(struct func_00562D90_arg0 *arg0, s32 arg1) {
    arg0->unk1174 = arg1;
}
