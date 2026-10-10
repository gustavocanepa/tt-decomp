#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s16, u8);                         /* extern */

struct func_003824F0_arg0 {
    char pad0[0x8];
    s16 unk8;
    char padA[0x10];
    u8 unk1A;
};

f32 func_003824F0(struct func_003824F0_arg0 *arg0) {
    return (func_00381890(arg0->unk8, arg0->unk1A) / 0x1.6800000000000p+7f) * 0x1.921fb40000000p+1f;
}
