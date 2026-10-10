#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0028A010();                            /* extern */
s32 func_0028D498(void *);                          /* extern */

extern char D_005C3278[];
struct func_0028D3A8_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

s32 func_0028D3A8(struct func_0028D3A8_arg0 *arg0) {
    func_0028A010();
    arg0->unk20 = -1;
    arg0->unk4 = (s32)D_005C3278;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = func_0028D498(arg0);
}
