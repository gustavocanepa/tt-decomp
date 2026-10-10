#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00571258_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_00571258(struct func_00571258_arg0 *arg0, s32 arg1) {
    arg0->unk10 = arg1;
}
