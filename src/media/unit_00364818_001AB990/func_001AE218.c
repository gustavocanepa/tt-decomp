#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AE218_arg0 {
    char pad0[0x140BC];
    s32 unk140BC;
    s32 unk140C0;
};

void func_001AE218(struct func_001AE218_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk140BC = (s32) ((arg1 >= 1) ? arg1 : 1);
    arg0->unk140C0 = (s32) ((arg2 >= 1) ? arg2 : 1);
}
