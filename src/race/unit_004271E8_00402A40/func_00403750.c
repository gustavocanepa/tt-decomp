#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00404AC8(void *, s32);             /* extern */

extern char D_005857E0[];
extern char D_00585818[];
extern char D_005D9560[];
struct func_00403750_arg0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    char pad10[0x1D];
    s8 unk2D;
};

s32 func_00403750(struct func_00403750_arg0 *arg0) {
    func_003FEC30(arg0, (s32)D_005857E0, (s32)D_00585818, arg0->unk8);
    arg0->unkC = (s32)D_005D9560;
    func_00404AC8(arg0, 0);
    arg0->unk2D = 1;
}
