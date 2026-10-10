#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A38_arg0 {
    char pad0[0x1176];
    s8 unk1176;
};

void func_00559A38(struct func_00559A38_arg0 *arg0, s8 arg1) {
    arg0->unk1176 = arg1;
}
