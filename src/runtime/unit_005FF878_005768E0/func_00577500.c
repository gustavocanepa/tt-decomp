#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005524A8(s32, s32);                    /* extern */

struct func_00577500_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    s32 unk10;
};

void func_00577500(struct func_00577500_arg0 *arg0) {
    func_005524A8(arg0->unkC, arg0->unk4 * arg0->unk10);
}
