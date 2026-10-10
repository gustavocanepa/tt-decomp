#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552958_arg0 {
    char pad0[0x23968];
    s32 unk23968;
};

s32 func_00552958(struct func_00552958_arg0 *arg0) {
    return arg0->unk23968;
}
