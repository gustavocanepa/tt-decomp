#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00245DC8_arg0 {
    char pad0[0x176];
    u8 unk176;
    u8 unk177;
};

void func_00245DC8(struct func_00245DC8_arg0 *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = (s32) arg0->unk176;
    *arg2 = (s32) arg0->unk177;
}
