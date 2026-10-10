#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558398_arg0 {
    char pad0[0x49];
    s8 unk49;
};

void func_00558398(struct func_00558398_arg0 *arg0, s8 arg1) {
    arg0->unk49 = arg1;
}
