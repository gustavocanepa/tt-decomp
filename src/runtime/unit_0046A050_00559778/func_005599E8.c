#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005599E8_arg0 {
    char pad0[0x1172];
    s8 unk1172;
};

void func_005599E8(struct func_005599E8_arg0 *arg0, s8 arg1) {
    arg0->unk1172 = arg1;
}
