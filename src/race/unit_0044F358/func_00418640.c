#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418640_arg0 {
    char pad0[0x344];
    s32 unk344;
};

s32 func_00418640(struct func_00418640_arg0 *arg0, s32 arg1) {
    return ((s32) arg0->unk344 >> (arg1 & 0x1F)) & 1;
}
