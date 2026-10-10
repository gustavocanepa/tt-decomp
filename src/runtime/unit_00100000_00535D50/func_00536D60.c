#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536D60_arg0 {
    char pad0[0x11C];
    s32 unk11C;
};

void func_00536D60(struct func_00536D60_arg0 *arg0, s32 arg1) {
    arg0->unk11C = (s32) ((arg0->unk11C & ~1) | (arg1 != 0));
}
