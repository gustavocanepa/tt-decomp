#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A28_arg0 {
    char pad0[0x1175];
    s8 unk1175;
};

void func_00559A28(struct func_00559A28_arg0 *arg0, s8 arg1) {
    arg0->unk1175 = arg1;
}
