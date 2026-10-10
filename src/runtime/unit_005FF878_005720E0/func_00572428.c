#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00572428_arg0 {
    char pad0[0x8];
    s32 unk8;
};
struct func_00572428_arg1 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_00572428(struct func_00572428_arg0 *arg0, struct func_00572428_arg1 *arg1) {
    return arg0->unk8 == arg1->unk8;
}
