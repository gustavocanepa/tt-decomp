#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004BCB38_arg0 {
    char pad0[0x404];
    s32 unk404;
};

s32 func_004BCB38(struct func_004BCB38_arg0 *arg0) {
    return arg0->unk404 == 0;
}
