#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0035D530_arg0 {
    char pad0[0x15C];
    s8 unk15C;
};

void func_0035D530(struct func_0035D530_arg0 *arg0, s8 arg1) {
    arg0->unk15C = arg1;
}
