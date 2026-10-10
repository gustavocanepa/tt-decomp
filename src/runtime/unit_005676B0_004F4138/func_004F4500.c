#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F41F0(s32);                         /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DB6A0[];
struct func_004F4500_arg0 {
    s32 unk0;
    char pad4[0x34];
    s32 unk38;
};

void func_004F4500(struct func_004F4500_arg0 *arg0, s32 arg1) {
    arg0->unk38 = (s32)D_005DB6A0;
    func_004F41F0(arg0->unk0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
