#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_003106C0(f32, f32);                        /* extern */

struct func_002EA230_arg0 {
    char pad0[0x482];
    s8 unk482;
    char pad483[0x25];
    f32 unk4A8;
    char pad4AC[0x88];
    f32 unk534;
    char pad538[0x8];
    u8 unk540;
    char pad541[0x1B];
    f32 unk55C;
};
struct func_002EA230_arg1 {
    char pad0[0x8];
    s16 unk8;
    char padA[0x2];
    s16 unkC;
};

void func_002EA230(struct func_002EA230_arg0 *arg0, struct func_002EA230_arg1 *arg1) {
    f32 var_f13;

    if (arg0->unk534 != 0x0.0p+0f) {
        var_f13 = arg0->unk55C;
        if (arg0->unk540 == 0) {
            var_f13 = -var_f13;
        }
        if (var_f13 >= -0x1.1c71c60000000p-2f) {
            arg0->unk4A8 = func_003106C0(arg0->unk4A8, var_f13);
        }
        if ((arg1->unk8 == 0) && (arg1->unkC == 0) && (arg0->unk55C < -0x1.1c71c60000000p-2f)) {
            arg0->unk482 = 1;
        }
    }
}
