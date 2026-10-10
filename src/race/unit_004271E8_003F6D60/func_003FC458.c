#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FC458_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_003FC458(struct func_003FC458_arg0 *arg0) {
    return *(s32 *)(0x585620 + (arg0->unk4 * 4));
}
