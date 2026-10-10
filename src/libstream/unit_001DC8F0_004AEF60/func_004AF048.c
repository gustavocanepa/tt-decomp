#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A48C0();                            /* extern */

extern char D_005DAE48[];
struct func_004AF048_arg0 {
    char pad0[0x8];
    s64 unk8;
    s32 unk10;
    s32 unk14;
};

s32 func_004AF048(struct func_004AF048_arg0 *arg0) {
    arg0->unk14 = (s32)D_005DAE48;
    func_004A48C0();
    arg0->unk8 = 0;
    arg0->unk10 = 0;
}
