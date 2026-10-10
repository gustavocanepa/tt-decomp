#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542870_arg0 {
    char pad0[0x8C];
    s32 unk8C;
};

s32 func_00542870(struct func_00542870_arg0 *arg0) {
    return arg0->unk8C;
}
