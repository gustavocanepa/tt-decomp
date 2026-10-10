#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553B68_arg0 {
    char pad0[0x184];
    s32 unk184;
};

s32 func_00553B68(struct func_00553B68_arg0 *arg0) {
    return arg0->unk184;
}
