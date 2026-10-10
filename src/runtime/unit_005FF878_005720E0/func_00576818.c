#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00576818_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

s32 func_00576818(struct func_00576818_arg0 *arg0) {
    return arg0->unk14 - arg0->unk10;
}
