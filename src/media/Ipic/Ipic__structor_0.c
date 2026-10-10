#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005B42F8[];
struct Ipic__structor_0_arg0 {
    char pad0[0x18];
    s32 unk18;
};

s32 Ipic__structor_0(struct Ipic__structor_0_arg0 *arg0) {
    arg0->unk18 = (s32)D_005B42F8;
}
