#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562AD8_arg0 {
    char pad0[0x114C];
    s32 unk114C;
};

void func_00562AD8(struct func_00562AD8_arg0 *arg0, s32 arg1) {
    arg0->unk114C = arg1;
}
