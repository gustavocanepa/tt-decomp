#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005537D0_arg0 {
    char pad0[0x1A0];
    s32 unk1A0;
};

s32 func_005537D0(struct func_005537D0_arg0 *arg0) {
    return arg0->unk1A0;
}
