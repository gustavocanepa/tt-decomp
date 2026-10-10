#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7618();                            /* extern */

extern char D_005C49B0[];
struct hIO__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
};

void hIO__structor_0(struct hIO__structor_0_arg0 *arg0) {
    func_002A7618();
    arg0->unk10 = 0;
    arg0->unk4 = (s32)D_005C49B0;
}
