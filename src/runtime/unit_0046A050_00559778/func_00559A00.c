#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A00_arg0 {
    char pad0[0x1173];
    s8 unk1173;
};

void func_00559A00(struct func_00559A00_arg0 *arg0, s8 arg1) {
    arg0->unk1173 = arg1;
}
