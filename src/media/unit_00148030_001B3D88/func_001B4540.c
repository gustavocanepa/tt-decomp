#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B8120();                            /* extern */
s32 func_001B9298(void *, s32);             /* extern */
s32 func_0020DCA0(void *, s32);             /* extern */

extern char D_005AE328[];
extern char D_005AE6E0[];
struct func_001B4540_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
    char pad30[0xA4];
    s16 unkD4;
    s16 unkD6;
    s16 unkD8;
    s16 unkDA;
};

void func_001B4540(struct func_001B4540_arg0 *arg0) {
    func_001B8120();
    arg0->unk4 = (s32)D_005AE328;
    arg0->unk2C = (s32)D_005AE6E0;
    arg0->unkD4 = 0;
    arg0->unkD6 = 0;
    arg0->unkD8 = 0;
    arg0->unkDA = 0;
    func_001B9298(arg0, 1);
    func_0020DCA0(arg0, 1);
}
