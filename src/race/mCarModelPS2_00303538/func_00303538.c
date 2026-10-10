#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00303538_arg0 {
    char pad0[0x6F0];
    s32 unk6F0;
    char pad6F4[0x9C];
    s32 unk790;
};

void func_00303538(struct func_00303538_arg0 *arg0) {
    arg0->unk6F0 = 0;
    arg0->unk790 = 0;
}
