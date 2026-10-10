#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00351D40_arg0 {
    char pad0[0x40];
    s32 unk40;
};

void func_00351D40(struct func_00351D40_arg0 *arg0, s32 arg1) {
    arg0->unk40 = (s32) ((arg0->unk40 & 0xFF00FFFF) | ((arg1 & 0xFF) << 0x10));
}
