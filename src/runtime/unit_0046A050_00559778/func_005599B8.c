#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005599B8_arg0 {
    char pad0[0x1170];
    s8 unk1170;
};

void func_005599B8(struct func_005599B8_arg0 *arg0, s8 arg1) {
    arg0->unk1170 = arg1;
}
