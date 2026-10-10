#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00427EC8_arg0 {
    char pad0[0x390];
    f32 unk390;
    char pad394[0x10];
    f32 unk3A4;
    char pad3A8[0x5C];
    s32 unk404;
    f32 unk408;
    char pad40C[0x3C];
    s32 unk448;
};

void func_00427EC8(struct func_00427EC8_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;

    if (arg0->unk404 != 0) {
        temp_f0 = arg0->unk390;
        if ((((arg0->unk3A4 - temp_f0) * arg0->unk408) + temp_f0) < fparg0) {
            arg0->unk448 = 1;
        }
    }
}
