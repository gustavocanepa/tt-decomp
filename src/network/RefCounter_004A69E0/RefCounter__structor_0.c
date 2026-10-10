#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005DACC0[];
struct RefCounter__structor_0_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

s32 RefCounter__structor_0(struct RefCounter__structor_0_arg0 *arg0) {
    arg0->unk18 = 0;
    arg0->unk1C = (s32)D_005DACC0;
}
