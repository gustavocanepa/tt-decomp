#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005436C0_arg0 {
    char pad0[0x100];
    s32 unk100;
};

void func_005436C0(struct func_005436C0_arg0 *arg0, s32 arg1) {
    arg0->unk100 = arg1;
}
