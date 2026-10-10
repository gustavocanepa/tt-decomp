#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00396308_arg0 {
    char pad0[0x96EC];
    s32 unk96EC;
};

void func_00396308(struct func_00396308_arg0 *arg0, s32 arg1) {
    arg0->unk96EC = arg1;
}
