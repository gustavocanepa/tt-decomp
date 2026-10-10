#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562978_arg0 {
    char pad0[0x1110];
    s32 unk1110;
};

void func_00562978(struct func_00562978_arg0 *arg0, s32 arg1) {
    arg0->unk1110 = arg1;
}
