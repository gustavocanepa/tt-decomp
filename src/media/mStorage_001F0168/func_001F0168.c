#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7618();                            /* extern */

extern char D_005B2380[];
struct func_001F0168_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
};

s32 func_001F0168(struct func_001F0168_arg0 *arg0) {
    func_002A7618();
    arg0->unk10 = -1;
    arg0->unk4 = (s32)D_005B2380;
}
