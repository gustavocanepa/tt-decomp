#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042D838();                            /* extern */

extern char D_005D9D28[];
struct GTSOUNDINSTRUMENTJAM__structor_1_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
};

void GTSOUNDINSTRUMENTJAM__structor_1(struct GTSOUNDINSTRUMENTJAM__structor_1_arg0 *arg0) {
    func_0042D838();
    arg0->unk20 = 0;
    arg0->unk1C = (s32)D_005D9D28;
}
