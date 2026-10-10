#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005634C0_arg0 {
    char pad0[0x44];
    s16 unk44;
};

void func_005634C0(struct func_005634C0_arg0 *arg0, s16 arg1) {
    arg0->unk44 = arg1;
}
