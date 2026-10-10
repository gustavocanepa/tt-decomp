#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005588E8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

void func_005588E8(struct func_005588E8_arg0 *arg0, s32 arg1) {
    arg0->unk1C = (s32) ((arg0->unk1C & 0xFFFF00FF) | ((arg1 & 0xFF) << 8));
}
