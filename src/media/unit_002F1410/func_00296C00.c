#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A2950();                            /* extern */

extern char D_005C3C58[];
struct func_00296C00_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

void func_00296C00(struct func_00296C00_arg0 *arg0) {
    func_002A2950();
    arg0->unk2C = 0;
    arg0->unk4 = (s32)D_005C3C58;
}
