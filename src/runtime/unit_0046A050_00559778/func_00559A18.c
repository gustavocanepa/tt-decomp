#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A18_arg0 {
    char pad0[0x1174];
    s8 unk1174;
};

void func_00559A18(struct func_00559A18_arg0 *arg0, s8 arg1) {
    arg0->unk1174 = arg1;
}
