#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00369150();                            /* extern */

struct mColorTransition__virtual_49_arg0 {
    char pad0[0x8];
    s32 unk8;
    s16 unkC;
    s8 unkE;
};

void mColorTransition__panOut(struct mColorTransition__virtual_49_arg0 *arg0) {
    func_00369150();
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unkE = 0;
}
