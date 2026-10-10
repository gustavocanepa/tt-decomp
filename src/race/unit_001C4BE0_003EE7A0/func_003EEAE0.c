#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003EEAE0_arg0 {
    char pad0[0x11F4];
    s32 unk11F4;
    s32 unk11F8;
    s32 unk11FC;
};

void func_003EEAE0(struct func_003EEAE0_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk11F4 = arg1;
    arg0->unk11F8 = arg2;
    arg0->unk11FC = 0;
}
