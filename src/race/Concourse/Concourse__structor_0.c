#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00385B20();                            /* extern */

extern char D_005D7108[];
struct Concourse__structor_0_arg0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void Concourse__structor_0(struct Concourse__structor_0_arg0 *arg0) {
    func_00385B20();
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk10 = (s32)D_005D7108;
}
