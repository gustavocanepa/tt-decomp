#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00385340_arg0 {
    char pad0[0x38];
    u16 unk38;
    char pad3A[0x1E];
    s32 unk58;
};

s32 func_00385340(struct func_00385340_arg0 *arg0, s32 arg1) {
    if (arg1 < (s32) arg0->unk38) {
        return arg0->unk58 + (arg1 * 8);
    }
    return 0;
}
