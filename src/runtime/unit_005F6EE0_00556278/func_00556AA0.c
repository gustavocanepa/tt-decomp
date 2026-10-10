#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556AA0_arg0 {
    char pad0[0x32];
    s16 unk32;
};

void func_00556AA0(struct func_00556AA0_arg0 *arg0, s16 arg1) {
    arg0->unk32 = arg1;
}
