#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00385510_arg0 {
    char pad0[0x8];
    u16 unk8;
    char padA[0xA];
    s32 unk14;
};

s32 func_00385510(struct func_00385510_arg0 *arg0, s32 arg1) {
    if (arg1 < (s32) arg0->unk8) {
        return arg0->unk14 + (arg1 * 8);
    }
    return 0;
}
