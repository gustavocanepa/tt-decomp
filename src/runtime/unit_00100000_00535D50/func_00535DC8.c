#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00535DC8_arg0 {
    char pad0[0x20];
    s16 unk20;
};

void func_00535DC8(struct func_00535DC8_arg0 *arg0, s16 arg1) {
    arg0->unk20 = arg1;
}
