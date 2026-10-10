#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0056D398_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_0056D398(struct func_0056D398_arg0 *arg0) {
    return arg0->unk4 - arg0->unk8;
}
