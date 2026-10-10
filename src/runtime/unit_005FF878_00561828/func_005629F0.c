#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005629F0_arg0 {
    char pad0[0x1130];
    s32 unk1130;
};

s32 func_005629F0(struct func_005629F0_arg0 *arg0) {
    return arg0->unk1130;
}
