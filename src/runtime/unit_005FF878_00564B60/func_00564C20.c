#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00564C20_arg0 {
    char pad0[0x8C];
    s8 unk8C;
};

void func_00564C20(struct func_00564C20_arg0 *arg0, s8 arg1) {
    arg0->unk8C = arg1;
}
