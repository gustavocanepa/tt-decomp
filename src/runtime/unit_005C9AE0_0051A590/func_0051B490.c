#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051B490_arg0_unk10 {
    char pad0[0x1124];
    s32 unk1124;
};
struct func_0051B490_arg0 {
    char pad0[0x10];
    struct func_0051B490_arg0_unk10 *unk10;
};

void func_0051B490(struct func_0051B490_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1124 = arg1;
}
