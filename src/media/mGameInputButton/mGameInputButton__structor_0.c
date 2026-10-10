#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7618();                            /* extern */
s32 func_004F6678(s32, s32, s32);       /* extern */

extern char D_005B98C0[];
struct mGameInputButton__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void mGameInputButton__structor_0(void *arg0) {
    func_002A7618();
    ((struct mGameInputButton__structor_0_arg0 *)arg0)->unk4 = (s32)D_005B98C0;
    func_004F6678(arg0 + 0x10, 0, 0x24);
}
