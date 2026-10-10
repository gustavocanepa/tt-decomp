#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9C0();                            /* extern */

extern char D_005D9F98[];
struct func_0044C660_arg0 {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
};

s32 func_0044C660(struct func_0044C660_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk3C = (s32)D_005D9F98;
    func_004AE9C0();
    arg0->unk30 = arg1;
    arg0->unk34 = arg2;
    arg0->unk38 = 0;
}
