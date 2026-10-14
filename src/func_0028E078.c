#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B45A0(void *, s32);                     /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005C3468[];
extern char D_005C3828[];
struct func_0028E078_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

void func_0028E078(struct func_0028E078_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32)D_005C3468;
    arg0->unk2C = (s32)D_005C3828;
    func_001B45A0(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0xF0, 4);
    }
}
