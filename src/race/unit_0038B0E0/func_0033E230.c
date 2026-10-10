#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0033E230_arg0 {
    char pad0[0xD94];
    s32 unkD94;
    char padD98[0xD73C];
    s32 unkE4D4;
};

void func_0033E230(struct func_0033E230_arg0 *arg0, s32 arg1) {
    if (arg0->unkD94 == 0) {
        arg0->unkE4D4 = arg1;
    }
}
