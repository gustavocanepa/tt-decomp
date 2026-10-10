#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F5040_arg1 {
    char pad0[0x56C];
    f32 unk56C;
    char pad570[0x174];
    f32 unk6E4;
};

f32 func_002F5040(s32 arg0, struct func_002F5040_arg1 *arg1) {
    return arg1->unk6E4 * arg1->unk56C;
}
