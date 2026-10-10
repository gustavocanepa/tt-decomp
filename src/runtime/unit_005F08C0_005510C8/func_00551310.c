#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551310_arg0 {
    char pad0[0xD00B];
    s8 unkD00B;
};

void func_00551310(struct func_00551310_arg0 *arg0, s8 arg1) {
    arg0->unkD00B = arg1;
}
