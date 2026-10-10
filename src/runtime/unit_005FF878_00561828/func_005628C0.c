#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005628C0_arg0 {
    char pad0[0x10E4];
    s32 unk10E4;
};

s32 func_005628C0(struct func_005628C0_arg0 *arg0) {
    return arg0->unk10E4;
}
