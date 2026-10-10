#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005285A0_arg0 {
    char pad0[0x458];
    s32 unk458;
};

s32 func_005285A0(struct func_005285A0_arg0 *arg0) {
    return arg0->unk458;
}
