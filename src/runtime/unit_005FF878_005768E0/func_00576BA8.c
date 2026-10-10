#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050E1A8(void *);                      /* extern */
s32 func_0050E1C8(s32);                         /* extern */

extern char D_005DB5C0[];
struct func_00576BA8_arg0 {
    char pad0[0x20];
    s32 unk20;
    char pad24[0x4];
    s32 unk28;
};

void func_00576BA8(struct func_00576BA8_arg0 *arg0, s32 arg1) {
    arg0->unk28 = (s32)D_005DB5C0;
    func_0050E1C8(arg0->unk20);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
