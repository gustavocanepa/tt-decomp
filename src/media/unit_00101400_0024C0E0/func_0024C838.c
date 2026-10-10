#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0024C838_arg0 {
    char pad0[0x64];
    f32 unk64;
    f32 unk68;
    s32 unk6C;
};

void func_0024C838(struct func_0024C838_arg0 *arg0, f32 fparg0) {
    if (arg0->unk6C != 0) {
        arg0->unk64 = fparg0;
        return;
    }
    arg0->unk68 = fparg0;
}
