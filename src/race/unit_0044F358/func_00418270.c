#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418270_arg0 {
    char pad0[0x32C];
    s32 unk32C;
};

s32 func_00418270(struct func_00418270_arg0 *arg0) {
    return arg0->unk32C;
}
