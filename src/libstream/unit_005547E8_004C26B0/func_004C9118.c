#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004C9118_arg0 {
    char pad0[0x2C30];
    s32 unk2C30;
    char pad2C34[0x1CC];
    s32 unk2E00;
    char pad2E04[0x1E4];
    s32 unk2FE8;
};

void func_004C9118(struct func_004C9118_arg0 *arg0) {
    if (arg0->unk2FE8 != 0) {
        arg0->unk2C30 = 0;
        arg0->unk2E00 = 0;
    }
}
