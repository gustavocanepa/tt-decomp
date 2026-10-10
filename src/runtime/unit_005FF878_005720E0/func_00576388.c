#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00576388_arg0 {
    char pad0[0x1B];
    s8 unk1B;
};

void func_00576388(struct func_00576388_arg0 *arg0, s8 arg1) {
    arg0->unk1B = arg1;
}
