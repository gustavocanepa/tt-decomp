#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00557700_arg0 {
    char pad0[0x34];
    s32 unk34;
};

void func_00557700(struct func_00557700_arg0 *arg0, s32 arg1) {
    arg0->unk34 = (s32) ((arg0->unk34 & 0xFF00FFFF) | ((arg1 & 0xFF) << 0x10));
}
