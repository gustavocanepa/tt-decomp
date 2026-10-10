#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A92D8(s32 *);                       /* extern */
s32 func_002C0EB0();                            /* extern */

extern char D_005C6F58[];
struct func_002B32C0_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_002B32C0(struct func_002B32C0_arg0 *arg0, s32 *arg1) {
    func_002C0EB0();
    arg0->unk4 = (s32)D_005C6F58;
    arg0->unk8 = (s32) *arg1;
    func_002A92D8(arg1);
}
