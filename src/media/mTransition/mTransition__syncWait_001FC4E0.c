#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_001C7410(s32);
struct mTransition__virtual_53_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void mTransition__syncWait(struct mTransition__virtual_53_arg0 *arg0) {
    while (arg0->unk18 == 1) {
        func_001C7410(1);
    }
}
