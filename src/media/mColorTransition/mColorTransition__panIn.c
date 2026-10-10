#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 mTransition__panIn();                            /* extern */

struct mColorTransition__virtual_50_arg0 {
    char pad0[0x20];
    f32 unk20;
};

void mColorTransition__panIn(struct mColorTransition__virtual_50_arg0 *arg0) {
    mTransition__panIn();
    arg0->unk20 = 1.0f;
}
