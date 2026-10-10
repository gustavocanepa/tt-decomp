#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A3F40_arg0 {
    char pad0[0x20A2D];
    s8 unk20A2D;
};

void func_003A3F40(struct func_003A3F40_arg0 *arg0) {
    arg0->unk20A2D = 1;
}
