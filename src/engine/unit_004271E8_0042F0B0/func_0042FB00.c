#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0042FB00_arg0 {
    char pad0[0xE4];
    s32 unkE4;
    s32 unkE8;
    s32 unkEC;
};

void func_0042FB00(struct func_0042FB00_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unkEC = (s32) (arg1 + 0x218AC);
    arg0->unkE4 = arg1;
    arg0->unkE8 = arg2;
}
