#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005B3608[];
s32 func_002A7618(void *);
struct mWatcher__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void mWatcher__structor_0(struct mWatcher__structor_0_arg0 *arg0) {
    func_002A7618(arg0);
    arg0->unk10 = 1;
    arg0->unk4 = (s32)D_005B3608;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
}
