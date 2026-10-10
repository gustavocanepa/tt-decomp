#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00554838();                            /* extern */

extern char D_005CDF18[];
struct func_0033E780_arg0 {
    char pad0[0x120];
    s32 unk120;
    char pad124[0x10];
    s32 unk134;
};

s32 func_0033E780(struct func_0033E780_arg0 *arg0) {
    func_00554838();
    arg0->unk120 = 2;
    arg0->unk134 = (s32)D_005CDF18;
}
