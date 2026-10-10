#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005591B8_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void func_005591B8(struct func_005591B8_arg0 *arg0, s32 arg1) {
    arg0->unk18 = (s32) ((arg0->unk18 & 0xFF00FFFF) | ((arg1 & 0xFF) << 0x10));
}
