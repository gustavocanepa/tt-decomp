#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0024C7D8_arg0 {
    char pad0[0x64];
    f32 unk64;
    f32 unk68;
    s32 unk6C;
};

f32 func_0024C7D8(struct func_0024C7D8_arg0 *arg0) {
    if (arg0->unk6C != 0) {
        return arg0->unk68;
    }
    return arg0->unk64;
}
