#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005562E0_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

void func_005562E0(struct func_005562E0_arg0 *arg0, s32 arg1) {
    arg0->unk3C = (s32) ((arg0->unk3C & 0xFF00FFFF) | ((arg1 & 0xFF) << 0x10));
}
