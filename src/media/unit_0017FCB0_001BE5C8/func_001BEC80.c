#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001BEC80_arg0 {
    char pad0[0x6C];
    s32 unk6C;
    char pad70[0x4];
    s32 unk74;
};

void func_001BEC80(struct func_001BEC80_arg0 *arg0, s32 arg1) {
    arg0->unk6C = arg1;
    arg0->unk74 = 0;
}
