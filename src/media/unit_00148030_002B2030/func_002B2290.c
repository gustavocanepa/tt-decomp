#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002C0EB0();                            /* extern */

extern char D_005C71B0[];
struct func_002B2290_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_002B2290(struct func_002B2290_arg0 *arg0, s32 *arg1) {
    func_002C0EB0();
    arg0->unk4 = (s32)D_005C71B0;
    arg0->unk8 = (s32) *arg1;
}
