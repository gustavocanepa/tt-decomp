#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004B2AC8();                                /* extern */

struct func_003FAE68_arg0 {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
};

void func_003FAE68(struct func_003FAE68_arg0 *arg0) {
    arg0->unk64 = 0;
    arg0->unk68 = func_004B2AC8();
}
