#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003035F8_arg0 {
    char pad0[0x6F0];
    f32 unk6F0;
    char pad6F4[0x9C];
    f32 unk790;
};

f32 func_003035F8(struct func_003035F8_arg0 *arg0, s32 arg1) {
    if (arg1 == 0) {
        return arg0->unk6F0 - arg0->unk790;
    }
    if (arg1 == 1) {
        return arg0->unk790;
    }
    return arg0->unk6F0;
}
