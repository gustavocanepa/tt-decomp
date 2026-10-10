#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0024C870_arg0 {
    char pad0[0x70];
    s32 unk70;
};

void func_0024C870(struct func_0024C870_arg0 *arg0, s32 arg1) {
    arg0->unk70 = arg1;
}
