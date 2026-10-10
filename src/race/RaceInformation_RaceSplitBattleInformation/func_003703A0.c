#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040EC90();                            /* extern */

struct func_003703A0_arg0 {
    char pad0[0x3E];
    u8 unk3E;
    char pad3F[0x4];
    u8 unk43;
    char pad44[0x45];
    s8 unk89;
    char pad8A[0x2E];
    s32 unkB8;
    char padBC[0x5C];
    s64 unk118;
    s32 unk120;
    char pad124[0xC];
    s32 unk130;
};

void func_003703A0(struct func_003703A0_arg0 *arg0, s64 arg1) {
    u8 temp_v1;

    arg0->unk118 = arg1;
    func_0040EC90();
    temp_v1 = arg0->unk3E;
    if (arg0->unk120 >= (s32) temp_v1) {
        arg0->unk120 = (s32) temp_v1;
    }
    arg0->unk130 = (s32) arg0->unk89;
    arg0->unkB8 = (s32) arg0->unk43;
}
